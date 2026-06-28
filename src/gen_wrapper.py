"""Generate Godot RefCounted wrapper classes for OCCT-Light C header functions.

Given a parsed C header, generates a Godot class that wraps every C function,
constant, and enum value as bound methods.
"""

import re
from pathlib import Path
from xml.sax.saxutils import escape

from parser import (
    CConstant, CEnum, CEnumValue, CField, CFunction, CParameter,
    CStruct, ParsedHeader,
)
from type_map import (
    ENUM_TYPES, HANDLE_TYPES,
    UINT64_ID_TYPES, VALUE_STRUCT_TYPES,
    c_type_to_godot_class, godot_param_type, godot_return_type,
    is_opaque_ptr_t_type, is_out_param, is_value_struct_type,
    CPP_TO_GODOT_TYPE, param_type_to_variant_type,
)


def _c_type_strip_ptr(t: str) -> str:
    """Remove trailing * and trailing cv-qualifiers from a C type, return the base type."""
    t = re.sub(r'\s+(const|volatile)\s*$', '', t)
    return t.rstrip("* \t")


def _filtered_constants(constants: list) -> list:
    """Filter out constants that can't be exposed as zero-arg methods."""
    # Platform/calling-convention macro names to exclude
    SKIP_NAMES = {"OCCTL_API", "OCCTL_CALL"}
    result = []
    for c in constants:
        name = c.name
        val = c.value.strip()
        if name in SKIP_NAMES:
            continue
        if name.endswith("_H") or "(" in name or ")" in name:
            continue
        if not val or val == "\\" or val.startswith("\\"):
            continue
        if '{' in val or '(' in val or ')' in val:
            continue
        if val.startswith("__"):
            continue
        result.append(c)
    return result


def _is_handle_ptr(c_type: str) -> bool:
    base = _c_type_strip_ptr(c_type).strip()
    return base in HANDLE_TYPES


def _is_value_ptr(c_type: str) -> bool:
    base = _c_type_strip_ptr(c_type).strip()
    return base in VALUE_STRUCT_TYPES


def _is_uint64_id_ptr(c_type: str) -> bool:
    base = _c_type_strip_ptr(c_type).strip()
    return base in UINT64_ID_TYPES


def _is_handle_type(t: str) -> bool:
    return t.strip() in HANDLE_TYPES


# ---------------------------------------------------------------
# Value conversion helpers
# ---------------------------------------------------------------

def _c_to_godot_val(c_type: str, expr: str) -> str:
    """Convert a C expression to a Godot value."""
    t = c_type.strip()
    if t == "const char*":
        return f"String({expr})"
    if t == "char*":
        return f"String({expr})"
    if t == "bool":
        return f"static_cast<bool>({expr})"
    if t in ("int32_t", "uint32_t", "uint16_t", "size_t"):
        return f"static_cast<int>({expr})"
    if t in ("int64_t", "uint64_t"):
        return f"static_cast<int64_t>({expr})"
    if t in ("double", "float"):
        return expr
    if t in ENUM_TYPES:
        return f"static_cast<int>({expr})"
    if t in UINT64_ID_TYPES:
        return f"static_cast<int64_t>({expr}.bits)"
    if is_value_struct_type(t):
        cls = c_type_to_godot_class(t)
        return f"{cls}::from_c({expr})"
    raise ValueError(f"Unknown C type in _c_to_godot_val: {t}")


def _godot_to_c_val(c_type: str, expr: str) -> str:
    """Convert a Godot expression to a C value."""
    t = c_type.strip()
    if t == "occtl_status_t":
        return f"static_cast<{t}>({expr})"
    if t in UINT64_ID_TYPES:
        return f"{t}{{static_cast<uint64_t>({expr})}}"
    if is_value_struct_type(t):
        return f"{expr}->to_c()"
    if t in ("int64_t", "uint64_t", "double", "float"):
        return f"static_cast<{t}>({expr})"
    if t in ("int32_t", "uint16_t", "size_t"):
        return f"static_cast<{t}>({expr})"
    if t == "uint32_t":
        return f"static_cast<{t}>({expr})"
    return expr


# ---------------------------------------------------------------
# Out-parameter handling
# ---------------------------------------------------------------

def _out_param_c_type(p: CParameter) -> str:
    """Get the C type for out-parameter declaration."""
    t = p.type_name.strip()
    if t.endswith("**"):
        return _c_type_strip_ptr(t) + "*"
    return _c_type_strip_ptr(t)


def _out_param_to_godot(p: CParameter, local_expr: str) -> list[str]:
    """Generate lines to convert an out-param to Godot dictionary entry."""
    t = p.type_name.strip()
    base = _c_type_strip_ptr(t).strip()
    name = p.name if p.name else "result"
    lines = []

    if t.endswith("**"):
        cls = c_type_to_godot_class(base) + "Handle"
        lines.append(f"if ({local_expr}) {{")
        lines.append(f"    Ref<{cls}> _h;")
        lines.append(f"    _h.instantiate();")
        lines.append(f'    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>({local_expr})));')
        lines.append(f'    _gdreturn["{name}"] = _h;')
        lines.append("}")
    elif base in UINT64_ID_TYPES:
        lines.append(f'_gdreturn["{name}"] = static_cast<int64_t>({local_expr}.bits);')
    elif base in VALUE_STRUCT_TYPES:
        cls = c_type_to_godot_class(base)
        lines.append(f'_gdreturn["{name}"] = {cls}::from_c({local_expr});')
    elif base == "occtl_status_t":
        lines.append(f'_gdreturn["{name}"] = static_cast<int>({local_expr});')
    elif base == "const char*":
        lines.append(f'_gdreturn["{name}"] = String({local_expr});')
    elif base == "char*":
        lines.append(f'_gdreturn["{name}"] = String({local_expr});')
    elif base in ("int32_t", "uint32_t", "uint16_t", "size_t", "int"):
        lines.append(f'_gdreturn["{name}"] = static_cast<int>({local_expr});')
    elif base in ("int64_t", "uint64_t"):
        lines.append(f'_gdreturn["{name}"] = static_cast<int64_t>({local_expr});')
    elif base in ("double", "float"):
        lines.append(f'_gdreturn["{name}"] = {local_expr};')
    elif base == "bool":
        lines.append(f'_gdreturn["{name}"] = static_cast<bool>({local_expr});')
    elif base in ENUM_TYPES:
        lines.append(f'_gdreturn["{name}"] = static_cast<int>({local_expr});')
    else:
        lines.append(f'_gdreturn["{name}"] = static_cast<int64_t>(reinterpret_cast<uintptr_t>({local_expr}));')
    return lines


def _out_param_return_expr(p: CParameter, local_expr: str) -> str:
    """For single out-param functions, generate the return expression."""
    t = p.type_name.strip()
    base = _c_type_strip_ptr(t).strip()

    if t.endswith("**"):
        cls = c_type_to_godot_class(base) + "Handle"
        return (f"[&]() -> Ref<{cls}> {{ if (!{local_expr}) return Ref<{cls}>(); "
                f"Ref<{cls}> _h; _h.instantiate(); "
                f"_h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>({local_expr}))); "
                f"return _h; }}()")
    if base in UINT64_ID_TYPES:
        return f"static_cast<int64_t>({local_expr}.bits)"
    if base in VALUE_STRUCT_TYPES:
        cls = c_type_to_godot_class(base)
        return f"{cls}::from_c({local_expr})"
    if base == "const char*":
        return f"String({local_expr})"
    if base in ("int32_t", "uint32_t", "uint16_t", "size_t", "int"):
        return f"static_cast<int>({local_expr})"
    if base in ("int64_t", "uint64_t"):
        return f"static_cast<int64_t>({local_expr})"
    if base in ("double", "float"):
        return local_expr
    if base == "bool":
        return f"static_cast<bool>({local_expr})"
    if base in ENUM_TYPES:
        return f"static_cast<int>({local_expr})"
    return f"static_cast<int64_t>(reinterpret_cast<uintptr_t>({local_expr}))"


# ---------------------------------------------------------------
# In-parameter handling
# ---------------------------------------------------------------

def _in_param_decl(p: CParameter) -> str | None:
    """Generate a local C variable declaration for an in-parameter.
    Returns None if no conversion needed (pass directly)."""
    t = p.type_name.strip()

    if t == "char*":
        return f"    godot::CharString _{p.name}_cs = {p.name}.utf8();\n    std::vector<char> _{p.name}_buf(_{p.name}_cs.get_data(), _{p.name}_cs.get_data() + _{p.name}_cs.length() + 1);\n    char* _{p.name}_c = _{p.name}_buf.data();"
    t_stripped = re.sub(r'\s+(const|volatile)\s*$', '', t)
    if t_stripped.startswith("const ") and t_stripped.endswith("*") and not t_stripped.endswith("**"):
        base_raw = _c_type_strip_ptr(t_stripped).strip()
        base = re.sub(r'^(const|volatile)\s+', '', base_raw).strip()
        if is_value_struct_type(base):
            return f"    {base_raw} _{p.name}_c = {p.name}->to_c();"
        if base in UINT64_ID_TYPES:
            return f"    {base} _{p.name}_c = {{static_cast<uint64_t>({p.name})}};"
        if base in HANDLE_TYPES:
            return None
        if base == "uint8_t":
            return f"    const uint8_t* _{p.name}_c = reinterpret_cast<const uint8_t*>(static_cast<uintptr_t>(static_cast<uint64_t>({p.name})));"
        return None

    return None


def _in_param_call_arg(p: CParameter) -> str:
    """Generate the function call argument for an in-parameter."""
    t = p.type_name.strip()
    name = p.name if p.name else ""

    if t.startswith("const ") and t.endswith("*"):
        base_raw = _c_type_strip_ptr(t).strip()
        base = re.sub(r'^(const|volatile)\s+', '', base_raw).strip()
        if is_value_struct_type(base):
            return f"&_{name}_c"
        if base in UINT64_ID_TYPES:
            return f"&_{name}_c"
        if base in HANDLE_TYPES:
            return f"reinterpret_cast<const {base}*>(static_cast<uintptr_t>({name}.is_valid() ? {name}->get_handle() : 0))"
        if base == "char":
            return f"{name}.utf8().get_data()"
        if base == "uint8_t":
            return f"_{name}_c"
        return name
    if t in UINT64_ID_TYPES:
        return f"{t}{{static_cast<uint64_t>({name})}}"
    if is_value_struct_type(t):
        return f"{name}->to_c()"
    if t == "occtl_status_t":
        return f"static_cast<{t}>({name})"
    if t in ("void",):
        return ""
    if t == "char*":
        return f"_{name}_c"
    if t.endswith("*"):
        base = _c_type_strip_ptr(t).strip()
        if base in HANDLE_TYPES:
            return f"reinterpret_cast<{base}*>(static_cast<uintptr_t>({name}.is_valid() ? {name}->get_handle() : 0))"
        return name
    return name


# ---------------------------------------------------------------
# Function classification
# ---------------------------------------------------------------

def _func_is_occtl_status(f: CFunction) -> bool:
    return f.return_type.strip() == "occtl_status_t"


def _func_return_type_mapped(f: CFunction) -> str:
    """Determine the Godot return type for a function wrapper."""
    if _func_is_occtl_status(f):
        out_params = [p for p in f.params if is_out_param(p.type_name, p.name, f.return_type)]
        if not out_params:
            return "int"  # just status
        handle_outs = [p for p in out_params if p.type_name.strip().endswith("**")]
        if len(out_params) == 1 and handle_outs:
            base = _c_type_strip_ptr(handle_outs[0].type_name).strip()
            inner = re.sub(r'^(const|volatile)\s+', '', base.rstrip("* \t")).strip()
            if inner == "char":
                return "Dictionary"
            if inner in UINT64_ID_TYPES:
                return "Dictionary"
            if inner in HANDLE_TYPES:
                return f"Ref<{c_type_to_godot_class(base)}Handle>"
            return "Dictionary"
        return "Dictionary"
    if f.return_type.strip() == "const occtl_error_t*":
        return "Dictionary"
    if f.return_type.strip() == "const char*":
        return "String"
    if f.return_type.strip() == "void":
        return "void"
    return godot_return_type(f.return_type)


# ---------------------------------------------------------------
# Body generation
# ---------------------------------------------------------------

def _generate_body(f: CFunction, wrapper_name: str) -> str:
    """Generate the C++ function body."""
    ret = f.return_type.strip()
    out_params = [p for p in f.params if is_out_param(p.type_name, p.name, ret)]
    in_params = [p for p in f.params if not is_out_param(p.type_name, p.name, ret)]
    lines = []
    ret_mapped = _func_return_type_mapped(f)

    # Special case: const occtl_error_t* return
    if ret == "const occtl_error_t*":
        lines.append("    const occtl_error_t* _err = ::%s();" % f.name)
        lines.append("    Dictionary _gdreturn;")
        lines.append('    _gdreturn["status"] = static_cast<int>(_err->status);')
        lines.append('    _gdreturn["message"] = String(_err->message);')
        lines.append('    _gdreturn["source_bits"] = static_cast<int64_t>(_err->source.bits);')
        lines.append('    _gdreturn["extended"] = static_cast<int64_t>(_err->extended);')
        lines.append("    return _gdreturn;")
        return "\n".join(lines)

    # Build call_args preserving parameter order
    call_args = []
    out_local_names = []
    for p in f.params:
        t = p.type_name.strip()
        name = p.name if p.name else ""
        if is_out_param(t, p.name, ret):
            base = _c_type_strip_ptr(t).strip()
            if t.endswith("**"):
                local = f"_{name}_val"
                lines.append(f"    {base}* {local} = nullptr;")
                call_args.append(f"&{local}")
                out_local_names.append((p, local, t))
            elif base in UINT64_ID_TYPES:
                local = f"_{name}_val"
                lines.append(f"    {base} {local} = {{}};")
                call_args.append(f"&{local}")
                out_local_names.append((p, local, t))
            elif is_value_struct_type(base):
                local = f"_{name}_val"
                lines.append(f"    {base} {local};")
                call_args.append(f"&{local}")
                out_local_names.append((p, local, t))
            elif base in ("const char*", "char*"):
                local = f"_{name}_val"
                lines.append(f"    {base} {local} = nullptr;")
                call_args.append(f"&{local}")
                out_local_names.append((p, local, t))
            elif base in HANDLE_TYPES:
                local = f"_{name}_val"
                lines.append(f"    {base}* {local} = nullptr;")
                call_args.append(f"&{local}")
                out_local_names.append((p, local, t))
            else:
                local = f"_{name}_val"
                lines.append(f"    {base} {local} = {{}};")
                call_args.append(f"&{local}")
                out_local_names.append((p, local, t))
        else:
            # In-param
            # Strip trailing cv-qualifiers (e.g. "const T* const" -> "const T*")
            t_stripped = re.sub(r'\s+(const|volatile)\s*$', '', t)
            if t_stripped.startswith("const ") and t_stripped.endswith("*") and not t_stripped.endswith("**"):
                base_raw = _c_type_strip_ptr(t_stripped).strip()
                base = re.sub(r'^(const|volatile)\s+', '', base_raw).strip()
                if is_value_struct_type(base):
                    lines.append(f"    {base_raw} _{name}_c = {name}->to_c();")
                    call_args.append(f"&_{name}_c")
                elif base in HANDLE_TYPES:
                    call_args.append(f"reinterpret_cast<const {base}*>(static_cast<uintptr_t>({name}.is_valid() ? {name}->get_handle() : 0))")
                elif base in UINT64_ID_TYPES:
                    lines.append(f"    {base} _{name}_c = {{static_cast<uint64_t>({name})}};")
                    call_args.append(f"&_{name}_c")
                elif base == "char":
                    call_args.append(f"{name}.utf8().get_data()")
                elif base == "uint8_t":
                    lines.append(f"    const uint8_t* _{name}_c = reinterpret_cast<const uint8_t*>(static_cast<uintptr_t>(static_cast<uint64_t>({name})));")
                    call_args.append(f"_{name}_c")
                elif base == "void":
                    call_args.append(f"reinterpret_cast<{base_raw}*>(static_cast<uintptr_t>(static_cast<int64_t>({name})))")
                else:
                    call_args.append(name if name else "")
            elif t in UINT64_ID_TYPES:
                call_args.append(f"{t}{{static_cast<uint64_t>({name})}}")
            elif t == "occtl_status_t":
                call_args.append(f"static_cast<{t}>({name})")
            elif is_opaque_ptr_t_type(t):
                call_args.append(f"reinterpret_cast<{t}>(static_cast<uintptr_t>(static_cast<int64_t>({name})))")
            elif is_value_struct_type(t):
                call_args.append(f"{name}->to_c()")
            elif t == "char*":
                local = f"_{name}_c"
                lines.append(f"    godot::CharString _{name}_cs = {name}.utf8();")
                lines.append(f"    std::vector<char> _{name}_buf(_{name}_cs.get_data(), _{name}_cs.get_data() + _{name}_cs.length() + 1);")
                lines.append(f"    char* {local} = _{name}_buf.data();")
                call_args.append(local)
            else:
                if t in ENUM_TYPES:
                    call_args.append(f"static_cast<{t}>({name})")
                    continue
                # Strip trailing cv-qualifiers for pointer detection
                t_clean = re.sub(r'\s+(const|volatile)\s*$', '', t)
                if t_clean.endswith("*"):
                    base = _c_type_strip_ptr(t_clean).strip()
                    if base in HANDLE_TYPES:
                        call_args.append(f"reinterpret_cast<{base}*>(static_cast<uintptr_t>({name}.is_valid() ? {name}->get_handle() : 0))")
                    elif base == "char":
                        lines.append(f"    godot::CharString _{name}_cs = {name}.utf8();")
                        lines.append(f"    std::vector<char> _{name}_buf(_{name}_cs.get_data(), _{name}_cs.get_data() + _{name}_cs.length() + 1);")
                        lines.append(f"    char* _{name}_c = _{name}_buf.data();")
                        call_args.append(f"_{name}_c")
                    elif base == "void":
                        call_args.append(f"reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<int64_t>({name})))")
                    elif is_opaque_ptr_t_type(base):
                        call_args.append(f"reinterpret_cast<{base}*>(static_cast<uintptr_t>(static_cast<int64_t>({name})))")
                    elif t_clean.startswith("const "):
                        call_args.append(name if name else "")
                    else:
                        call_args.append(name if name else "")
                else:
                    call_args.append(name if name else "")

    # Call the C function
    if _func_is_occtl_status(f):
        lines.append(f"    occtl_status_t _status = ::{f.name}({', '.join(call_args)});")
    else:
        if ret == "void":
            lines.append(f"    ::{f.name}({', '.join(call_args)});")
        else:
            lines.append(f"    auto _result = ::{f.name}({', '.join(call_args)});")

    # Build return
    if _func_is_occtl_status(f):
        if not out_params:
            lines.append("    return static_cast<int>(_status);")
        elif len(out_params) == 1 and out_params[0].type_name.strip().endswith("**"):
            p, local, _ = out_local_names[0]
            base = _c_type_strip_ptr(p.type_name).strip()
            inner = re.sub(r'^(const|volatile)\s+', '', base.rstrip("* \t")).strip()
            if inner in UINT64_ID_TYPES:
                # For uint64 ID types, the ** out param is an array of IDs, not a handle
                lines.append("    Dictionary _gdreturn;")
                lines.append(f'    _gdreturn["status"] = static_cast<int>(_status);')
                lines.append(f'    _gdreturn["out"] = static_cast<int64_t>(reinterpret_cast<uintptr_t>({local}));')
                lines.append("    return _gdreturn;")
            elif inner == "char" or (p.type_name.strip().startswith("const ") and inner == "char"):
                lines.append("    Dictionary _gdreturn;")
                lines.append(f'    _gdreturn["status"] = static_cast<int>(_status);')
                lines.append(f'    _gdreturn["out"] = String({local});')
                lines.append("    return _gdreturn;")
            elif inner in HANDLE_TYPES:
                cls = c_type_to_godot_class(base) + "Handle"
                lines.append(f"    if (_status != OCCTL_OK) {{ return Ref<{cls}>(); }}")
                lines.append(f"    if (!{local}) {{ return Ref<{cls}>(); }}")
                lines.append(f"    Ref<{cls}> _h;")
                lines.append(f"    _h.instantiate();")
                lines.append(f"    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>({local})));")
                lines.append(f"    return _h;")
            else:
                lines.append("    Dictionary _gdreturn;")
                lines.append(f'    _gdreturn["status"] = static_cast<int>(_status);')
                lines.append(f'    _gdreturn["out"] = static_cast<int64_t>(reinterpret_cast<uintptr_t>({local}));')
                lines.append("    return _gdreturn;")
        else:
            lines.append("    Dictionary _gdreturn;")
            lines.append('    _gdreturn["status"] = static_cast<int>(_status);')
            for p, local, t in out_local_names:
                lines.extend(_out_param_to_godot_lines(p, local))
            lines.append("    return _gdreturn;")
    else:
        if ret == "void":
            pass
        elif out_params:
            if len(out_params) == 1:
                p, local, _ = out_local_names[0]
                base = _c_type_strip_ptr(p.type_name).strip()
                if base in VALUE_STRUCT_TYPES:
                    cls = c_type_to_godot_class(base)
                    lines.append(f"    return {cls}::from_c({local});")
                elif base in UINT64_ID_TYPES:
                    lines.append(f"    return static_cast<int64_t>({local}.bits);")
                elif base == "const char*":
                    lines.append(f"    return String({local});")
                else:
                    lines.append(f"    return {local};")
            else:
                lines.append("    Dictionary _gdreturn;")
                for p, local, t in out_local_names:
                    lines.extend(_out_param_to_godot_lines(p, local))
                lines.append("    return _gdreturn;")
        else:
            lines.append(f"    return {_c_to_godot_return(ret, '_result')};")

    if not lines:
        lines.append("    return {};")
    return "\n".join(lines)


def _c_to_godot_return(c_type: str, expr: str) -> str:
    """Convert a non-status C return value to Godot."""
    t = c_type.strip()
    if t in ENUM_TYPES:
        return f"static_cast<int>({expr})"
    if t in UINT64_ID_TYPES:
        return f"static_cast<int64_t>({expr}.bits)"
    if is_value_struct_type(t):
        cls = c_type_to_godot_class(t)
        return f"{cls}::from_c({expr})"
    if t == "const char*":
        return f"String({expr})"
    if t == "bool":
        return f"static_cast<bool>({expr})"
    if t in ("int32_t", "uint32_t", "uint16_t", "uint8_t", "size_t", "int"):
        return f"static_cast<int>({expr})"
    if t in ("int64_t", "uint64_t"):
        return f"static_cast<int64_t>({expr})"
    return expr


def _out_param_to_godot_lines(p: CParameter, local_expr: str) -> list[str]:
    """Generate lines to add out-param value to dictionary."""
    t = p.type_name.strip()
    base = _c_type_strip_ptr(t).strip()
    name = p.name if p.name else "result"

    if t.endswith("**"):
        inner = re.sub(r'^(const|volatile)\s+', '', base.rstrip("* \t")).strip()
        if inner == "char":
            return [f'    _gdreturn["{name}"] = String({local_expr});']
        if inner in UINT64_ID_TYPES:
            return [f'    _gdreturn["{name}"] = static_cast<int64_t>(reinterpret_cast<uintptr_t>({local_expr}));']
        if inner in HANDLE_TYPES:
            cls = c_type_to_godot_class(base) + "Handle"
            return [
                f"    if ({local_expr}) {{",
                f"        Ref<{cls}> _h;",
                f"        _h.instantiate();",
                f"        _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>({local_expr})));",
                f'        _gdreturn["{name}"] = _h;',
                f"    }}",
            ]
        return [f'    _gdreturn["{name}"] = static_cast<int64_t>(reinterpret_cast<uintptr_t>({local_expr}));']
    if base in ENUM_TYPES:
        return [f'    _gdreturn["{name}"] = static_cast<int>({local_expr});']
    if base in UINT64_ID_TYPES:
        return [f'    _gdreturn["{name}"] = static_cast<int64_t>({local_expr}.bits);']
    if is_value_struct_type(base):
        cls = c_type_to_godot_class(base)
        return [f'    _gdreturn["{name}"] = {cls}::from_c({local_expr});']
    if base == "const char*":
        return [f'    _gdreturn["{name}"] = String({local_expr});']
    if base in ("int32_t", "uint32_t", "uint16_t", "uint8_t", "size_t", "int"):
        return [f'    _gdreturn["{name}"] = static_cast<int>({local_expr});']
    if base in ("int64_t", "uint64_t"):
        return [f'    _gdreturn["{name}"] = static_cast<int64_t>({local_expr});']
    if base in ("double", "float"):
        return [f'    _gdreturn["{name}"] = {local_expr};']
    if base == "bool":
        return [f'    _gdreturn["{name}"] = static_cast<bool>({local_expr});']
    return [f'    _gdreturn["{name}"] = static_cast<int64_t>(reinterpret_cast<uintptr_t>({local_expr}));']


# ---------------------------------------------------------------
# Method declarations
# ---------------------------------------------------------------

def _method_args_decl(f: CFunction) -> str:
    """Generate the parameter list for the Godot method declaration."""
    in_params = [p for p in f.params if not is_out_param(p.type_name, p.name, f.return_type)]
    if not in_params:
        return "void"
    args = []
    for p in in_params:
        gt = godot_param_type(p.type_name)
        if gt in ("String", "Variant", "Array", "Dictionary", "PackedByteArray") or gt.startswith("Ref<"):
            args.append(f"const {gt}& {p.name}")
        else:
            args.append(f"{gt} {p.name}")
    return ", ".join(args)


def _method_arg_names(f: CFunction) -> str:
    """Generate the argument name list for D_METHOD."""
    in_params = [p for p in f.params if not is_out_param(p.type_name, p.name, f.return_type)]
    return "".join(f', "{p.name}"' for p in in_params)


def _wrapper_class_name(header_include: str) -> str:
    """Derive wrapper class name from header filename."""
    stem = Path(header_include).stem  # occtl_core → OcctlCoreWrapper
    parts = stem.replace("occtl_", "", 1).split("_")
    return "Occtl" + "".join(p.capitalize() for p in parts) + "Wrapper"


# ---------------------------------------------------------------
# Header generation
# ---------------------------------------------------------------

def generate_wrapper_header(
    parsed: ParsedHeader,
    value_type_includes: list[str],
) -> str:
    """Generate the .h file for a wrapper class from a parsed header."""
    cls = _wrapper_class_name(parsed.header_include)
    guard = f"{cls.upper()}_H"

    functions = parsed.functions

    lines = [
        f"#ifndef {guard}",
        f"#define {guard}",
        "",
        "#include <godot_cpp/classes/ref.hpp>",
        "#include <godot_cpp/core/class_db.hpp>",
        "#include <godot_cpp/variant/dictionary.hpp>",
        "#include <godot_cpp/variant/array.hpp>",
        "#include <godot_cpp/variant/packed_byte_array.hpp>",
        "#include <godot_cpp/variant/string.hpp>",
        "#include <godot_cpp/variant/vector3.hpp>",
        "#include <godot_cpp/variant/vector2.hpp>",
        "#include <godot_cpp/variant/transform3d.hpp>",
        "#include <godot_cpp/variant/aabb.hpp>",
        "#include <godot_cpp/variant/color.hpp>",
        "#include <cstdint>",
        f'#include "occtl/{parsed.header_include}"',
        "",
    ]

    for inc in sorted(set(value_type_includes)):
        lines.append(f'#include "{inc}"')

    lines.extend([
        "",
        "using namespace godot;",
        "",
        f"class {cls} : public godot::RefCounted {{",
        f"    GDCLASS({cls}, godot::RefCounted)",
        "protected:",
        "    static void _bind_methods();",
        "public:",
    ])

    # Constants as zero-arg methods (prefixed to avoid macro name conflicts)
    for c in _filtered_constants(parsed.constants):
        ret = _constant_godot_return_type(c)
        lines.append(f"    {ret} const_{c.name}(); // NOLINT")
    # Enum values as zero-arg methods
    for enum in parsed.enums:
        for ev in enum.values:
            lines.append(f"    int {ev.name}(); // NOLINT")

    # Functions
    for f in functions:
        ret_mapped = _func_return_type_mapped(f)
        args_decl = _method_args_decl(f)
        lines.append(f"    {ret_mapped} {f.name}({args_decl}); // NOLINT")

    if not functions and not parsed.constants and not parsed.enums:
        lines.append("    void _unused();")
    lines.extend([
        "};",
        "",
        f"#endif // {guard}",
        "",
    ])
    return "\n".join(lines)


def _constant_godot_return_type(c: CConstant) -> str:
    """Guess the Godot return type for a #define constant based on its value."""
    v = c.value.strip()
    while v.startswith("(") and v.endswith(")"):
        v = v[1:-1].strip()
    v_lower = v.lower()
    if v_lower in ("true", "false"):
        return "bool"
    if "." in v or "e" in v_lower:
        return "double"
    if v_lower.startswith("0x"):
        return "int"
    try:
        int(v)
        return "int"
    except ValueError:
        pass
    if any(c in v for c in "+-*/"):
        return "double" if ("." in v or "pi" in v_lower) else "int"
    if v_lower in ("null", "nullptr", "null"):
        return "int64_t"
    return "int64_t"


# ---------------------------------------------------------------
# Source generation
# ---------------------------------------------------------------

def generate_wrapper_source(
    parsed: ParsedHeader,
) -> str:
    """Generate the .cpp file for a wrapper class."""
    cls = _wrapper_class_name(parsed.header_include)
    functions = parsed.functions

    has_char_ptr = any(p.type_name.strip() == "char*" for f in functions for p in f.params)

    lines = [
        f'#include "{cls}.h"',
        "",
        f'#include "occtl/{parsed.header_include}"',
        "",
    ]

    if has_char_ptr:
        lines.append("#include <vector>")
        lines.append("")

    # _bind_methods
    lines.append(f"void {cls}::_bind_methods() {{")

    for c in _filtered_constants(parsed.constants):
        lines.append(f'    godot::ClassDB::bind_method(godot::D_METHOD("const_{c.name}"), &{cls}::const_{c.name});')
    for enum in parsed.enums:
        for ev in enum.values:
            lines.append(f'    godot::ClassDB::bind_method(godot::D_METHOD("{ev.name}"), &{cls}::{ev.name});')
    for f in functions:
        lines.append(f'    godot::ClassDB::bind_method(godot::D_METHOD("{f.name}"{_method_arg_names(f)}), &{cls}::{f.name});')

    if not functions and not parsed.constants and not parsed.enums:
        lines.append(f"    godot::ClassDB::bind_method(godot::D_METHOD(\"_unused\"), &{cls}::_unused);")
    lines.append("}")
    lines.append("")

    # Implement constant methods
    for c in _filtered_constants(parsed.constants):
        ret = _constant_godot_return_type(c)
        body = _generate_constant_body(c)
        lines.append(f"{ret} {cls}::const_{c.name}() {{ // NOLINT")
        lines.append(f"    {body}")
        lines.append("}")
        lines.append("")

    # Implement enum value methods
    for enum in parsed.enums:
        for ev in enum.values:
            lines.append(f"int {cls}::{ev.name}() {{ // NOLINT")
            lines.append(f"    return {ev.value};")
            lines.append("}")
            lines.append("")

    # Implement functions
    for f in functions:
        ret_mapped = _func_return_type_mapped(f)
        args_decl = _method_args_decl(f)
        lines.append(f"{ret_mapped} {cls}::{f.name}({args_decl}) {{ // NOLINT")
        body = _generate_body(f, cls)
        if body.strip():
            lines.append(body)
        else:
            lines.append("    return {};")
        lines.append("}")
        lines.append("")

    if not functions and not parsed.constants and not parsed.enums:
        lines.append(f"void {cls}::_unused() {{}}")
        lines.append("")

    return "\n".join(lines)


def _generate_constant_body(c: CConstant) -> str:
    """Generate the body for a constant wrapper function."""
    v = c.value.strip()
    ret = _constant_godot_return_type(c)

    if ret == "double":
        try:
            evaluated = _eval_const(v)
            return f"return {evaluated};"
        except Exception:
            return f"return {v};"
    elif ret == "int":
        try:
            evaluated = int(_eval_simple_int(v))
            return f"return {evaluated};"
        except Exception:
            return f"return {v};"
    elif ret == "bool":
        if v.lower() in ("true", "false"):
            return f"return {v.lower()};"
        return f"return {v};"
    else:
        return f"return {v};"


def _eval_const(expr: str) -> str:
    """Try to evaluate a constant expression."""
    e = expr.strip()
    while e.startswith("(") and e.endswith(")"):
        e = e[1:-1].strip()
    replacements = {
        "OCCTL_PI": "3.14159265358979323846",
        "OCCTL_TWO_PI": "6.28318530717958647692",
        "OCCTL_PI_OVER_TWO": "1.57079632679489661923",
        "OCCTL_RAD_PER_DEG": "0.01745329251994329577",
        "OCCTL_ANGLE_1_DEG_RAD": "0.01745329251994329577",
        "OCCTL_ANGLE_5_DEG_RAD": "0.08726646259971647885",
        "OCCTL_ANGLE_20_DEG_RAD": "0.34906585039886591541",
        "OCCTL_ANGLE_30_DEG_RAD": "0.52359877559829887308",
        "OCCTL_ANGLE_90_DEG_RAD": "1.57079632679489661923",
    }
    for k, val in replacements.items():
        e = e.replace(k, val)
    import ast
    import operator as op
    allowed_ops = {
        ast.Add: op.add, ast.Sub: op.sub, ast.Mult: op.mul,
        ast.Div: op.truediv, ast.USub: op.neg, ast.UAdd: op.pos,
        ast.Pow: op.pow,
    }
    def _eval(node):
        if isinstance(node, ast.Expression):
            return _eval(node.body)
        if isinstance(node, ast.Constant):
            return node.value
        if isinstance(node, ast.UnaryOp):
            return allowed_ops[type(node.op)](_eval(node.operand))
        if isinstance(node, ast.BinOp):
            return allowed_ops[type(node.op)](_eval(node.left), _eval(node.right))
        raise ValueError(f"Unsupported: {type(node)}")
    result = _eval(ast.parse(e, mode="eval"))
    return repr(result)


def _eval_simple_int(expr: str) -> str:
    """Try to evaluate an integer expression."""
    e = expr.strip()
    while e.startswith("(") and e.endswith(")"):
        e = e[1:-1].strip()
    replacements = {
        "OCCTL_UID_WIRE_SIZE": "16",
        "OCCTL_REF_UID_WIRE_SIZE": "16",
        "OCCTL_REP_UID_WIRE_SIZE": "16",
        "OCCTL_RUNTIME_INIT_INFO_VERSION_1": "1",
        "OCCTL_ABI_VERSION": "1",
    }
    for k, val in replacements.items():
        e = e.replace(k, val)
    try:
        import ast, operator as op
        allowed_ops = {
            ast.Add: op.add, ast.Sub: op.sub, ast.Mult: op.mul,
            ast.FloorDiv: op.floordiv, ast.USub: op.neg,
        }
        def _eval(node):
            if isinstance(node, ast.Expression):
                return _eval(node.body)
            if isinstance(node, ast.Constant):
                return node.value
            if isinstance(node, ast.UnaryOp):
                return allowed_ops[type(node.op)](_eval(node.operand))
            if isinstance(node, ast.BinOp):
                return allowed_ops[type(node.op)](_eval(node.left), _eval(node.right))
            raise ValueError
        return str(int(_eval(ast.parse(e, mode="eval"))))
    except Exception:
        return e


# ---------------------------------------------------------------
# Doc XML generation
# ---------------------------------------------------------------

def generate_wrapper_doc_xml(parsed: ParsedHeader) -> str:
    """Generate XML doc for a wrapper class."""
    cls = _wrapper_class_name(parsed.header_include)
    methods = []

    for c in parsed.constants:
        ret = _constant_godot_return_type(c)
        methods.append(f'\t\t<method name="{escape(c.name)}">')
        methods.append(f'\t\t\t<return type="{ret}" />')
        methods.append("\t\t\t<description>")
        methods.append(f"\t\t\t\t{c.doc_comment or f'Constant wrapper for #define {c.name}'}.")
        methods.append("\t\t\t</description>")
        methods.append("\t\t</method>")

    for enum in parsed.enums:
        for ev in enum.values:
            methods.append(f'\t\t<method name="{escape(ev.name)}">')
            methods.append('\t\t\t<return type="int" />')
            methods.append("\t\t\t<description>")
            methods.append(f"\t\t\t\tEnum value {ev.name} = {ev.value}.")
            methods.append("\t\t\t</description>")
            methods.append("\t\t</method>")

    for f in parsed.functions:
        ret_mapped = _func_return_type_mapped(f)
        methods.append(f'\t\t<method name="{escape(f.name)}">')
        methods.append(f'\t\t\t<return type="{ret_mapped}" />')
        in_params = [p for p in f.params if not is_out_param(p.type_name, p.name, f.return_type)]
        for i, p in enumerate(in_params):
            gt = godot_param_type(p.type_name)
            methods.append(f'\t\t\t<argument index="{i}" name="{escape(p.name)}" type="{gt}" />')
        methods.append("\t\t\t<description>")
        methods.append(f"\t\t\t\t{f.doc_comment or 'Generated binding.'}")
        methods.append("\t\t\t</description>")
        methods.append("\t\t</method>")

    methods_xml = "\n".join(methods)
    return (
        '<?xml version="1.0" encoding="UTF-8" ?>\n'
        f'<class name="{cls}" inherits="RefCounted" version="4.0" '
        'xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" '
        'xsi:noNamespaceSchemaLocation="https://raw.githubusercontent.com/godotengine/godot/master/doc/class.xsd">\n'
        "\t<brief_description>\n"
        f"\t\tWrapper for {parsed.header_include}.\n"
        "\t</brief_description>\n"
        "\t<description>\n"
        f"\t\tAuto-generated wrapper for the OCCT-Light C header {parsed.header_include}.\n"
        "\t</description>\n"
        "\t<tutorials>\n\t</tutorials>\n"
        "\t<methods>\n"
        f"{methods_xml}\n"
        "\t</methods>\n"
        "</class>\n"
    )


# ---------------------------------------------------------------
# GDScript test generation
# ---------------------------------------------------------------

def generate_gdscript_tests(
    parsed: ParsedHeader,
    wrapper_name: str,
) -> str:
    """Generate a GDScript test file for the wrapper class."""
    cls = _wrapper_class_name(parsed.header_include)
    lines = [
        f"class_name Test{cls}",
        "",
        f"var _w: {cls}",
        "",
        "func _init() -> void:",
        f"    self._w = {cls}.new()",
        "",
    ]

    for c in parsed.constants:
        lines.append(f"static func test_{c.name}() -> String:")
        ret = _constant_godot_return_type(c)
        if ret == "double":
            lines.append(f"    var v = {cls}.new().{c.name}()")
            lines.append("    if v == null: return \"Failed: {c.name} returned null\"")
        elif ret == "int":
            lines.append(f"    var v = {cls}.new().{c.name}()")
            lines.append("    if v == null: return \"Failed\"")
        elif ret == "bool":
            lines.append(f"    var v = {cls}.new().{c.name}()")
        else:
            lines.append(f"    var v = {cls}.new().{c.name}()")
        lines.append('    return ""')
        lines.append("")

    for enum in parsed.enums:
        for ev in enum.values:
            lines.append(f"static func test_{ev.name}() -> String:")
            lines.append(f"    var v = {cls}.new().{ev.name}()")
            lines.append("    if v < 0: return \"Failed: enum value negative\"")
            lines.append('    return ""')
            lines.append("")

    for f in parsed.functions:
        lines.append(f"static func test_{f.name}() -> String:")
        in_params = [p for p in f.params if not is_out_param(p.type_name, p.name, f.return_type)]
        args_list = []
        for p in in_params:
            t = p.type_name.strip()
            gt = godot_param_type(p.type_name)
            if gt == "int" or gt == "int64_t":
                args_list.append("0")
            elif gt == "double" or gt == "float":
                args_list.append("0.0")
            elif gt == "bool":
                args_list.append("false")
            elif gt == "String":
                args_list.append('""')
            elif gt.startswith("Ref<"):
                args_list.append("null")
            elif gt == "Dictionary":
                args_list.append("{}")
            elif gt == "PackedByteArray":
                args_list.append("PackedByteArray()")
            else:
                args_list.append("null")
        call = f"{f.name}({', '.join(args_list)})" if args_list else f"{f.name}()"
        ret_mapped = _func_return_type_mapped(f)
        if ret_mapped == "void":
            lines.append(f"    {cls}.new().{call}")
            lines.append('    return ""')
        elif ret_mapped == "bool":
            lines.append(f"    var _v = {cls}.new().{call}")
            lines.append('    return ""')
        else:
            lines.append(f"    var _v = {cls}.new().{call}")
            lines.append("    if _v == null: return \"Failed: {f.name} returned null\"")
            lines.append('    return ""')
        lines.append("")

    return "\n".join(lines)
