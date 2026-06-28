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
    _resolve_typedef,
    CPP_TO_GODOT_TYPE, param_type_to_variant_type,
)


def _c_type_strip_ptr(t: str) -> str:
    t = re.sub(r'\s+(const|volatile)\s*$', '', t)
    return t.rstrip("* \t")


def _filtered_constants(constants: list) -> list:
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


# ---------------------------------------------------------------
# Out-param classification
# ---------------------------------------------------------------

OUT_PARAM_PRIM_TYPES: dict[str, str] = {
    "uint32_t": "OcctlUint32",
    "int32_t": "OcctlInt32",
    "uint16_t": "OcctlInt32",
    "uint8_t": "OcctlUint8",  # scalar only; use OcctlByteArray for uint8_t*
    "size_t": "OcctlSize",
    "int": "OcctlInt32",
    "int64_t": "OcctlInt64",
    "uint64_t": "OcctlUint64",
    "double": "OcctlDouble",
    "float": "OcctlDouble",
    "bool": "OcctlBool",
}


# Functions whose pointer-to-value-struct params can be nullptr (use defaults).
# Key = C function name, value = set of param names that are nullable.
DEFAULT_NULLABLE_PARAMS: dict[str, set[str]] = {
    "occtl_runtime_init": {"info"},
    "occtl_heal_shape": {"options"},
    "occtl_heal_unify_same_domain": {"options"},
}


def _is_const_char_double_ptr(t: str) -> bool:
    t = t.strip()
    return t in ("const char**", "const char * *")


def _out_param_wrapper_class(base: str, full_type: str = "") -> str | None:
    """Return the Godot wrapper class for an out-param C type.
    Returns None for handle double-ptrs, const occtl_error_t**, etc."""
    resolved = _resolve_typedef(base)
    if resolved in HANDLE_TYPES:
        return None
    # uint8_t* buffer out-params → OcctlByteArray
    ft = full_type.strip() if full_type else ""
    if resolved == "uint8_t" and (ft.endswith("*") and not ft.endswith("**")):
        return "OcctlByteArray"
    if resolved in UINT64_ID_TYPES:
        return c_type_to_godot_class(resolved)
    if resolved in VALUE_STRUCT_TYPES:
        return c_type_to_godot_class(resolved)
    if resolved in OUT_PARAM_PRIM_TYPES:
        return OUT_PARAM_PRIM_TYPES[resolved]
    if resolved in ENUM_TYPES:
        return "OcctlInt32"
    if resolved in ("const char", "char"):
        if _is_const_char_double_ptr(ft):
            return "OcctlStringArray"
        return "OcctlString"
    return None


def _is_direct_return_out_param(p: CParameter) -> bool:
    """True if this out-param should be returned directly instead of
    kept as a method parameter.  Handles: handle**, const occtl_error_t**."""
    t = p.type_name.strip()
    if t.endswith("**"):
        return True
    return False


def _is_occtl_error_param(p: CParameter) -> bool:
    t = p.type_name.strip()
    base = _c_type_strip_ptr(t).strip()
    return base == "occtl_error_t" and t.endswith("**")


# ---------------------------------------------------------------
# Value conversion helpers
# ---------------------------------------------------------------

def _c_to_godot_val(c_type: str, expr: str) -> str:
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
# In-parameter handling
# ---------------------------------------------------------------

def _in_param_decl(p: CParameter) -> str | None:
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
            return f"    const uint8_t* _{p.name}_c = {p.name}.ptr();"
        return None
    return None


def _in_param_call_arg(p: CParameter) -> str:
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
    ret = f.return_type.strip()
    out_params = [p for p in f.params if is_out_param(p.type_name, p.name, ret)]

    # const occtl_error_t* → Ref<OcctlError>
    if ret == "const occtl_error_t*":
        return "Ref<OcctlError>"

    # const char* → String
    if ret == "const char*":
        return "String"

    # Handle** out-params returned directly (first such param wins)
    handle_outs = [p for p in out_params if _is_direct_return_out_param(p)]
    non_handle_outs = [p for p in out_params if not _is_direct_return_out_param(p)]

    if handle_outs:
        p = handle_outs[0]
        base = _c_type_strip_ptr(p.type_name).strip()
        inner = re.sub(r'^(const|volatile)\s+', '', base.rstrip("* \t")).strip()
        if inner in HANDLE_TYPES:
            return f"Ref<{c_type_to_godot_class(base)}Handle>"
        return "int"  # fallback

    # No handle out-params → return mapped C return type
    if ret == "void":
        return "void"
    if _func_is_occtl_status(f):
        return "int"
    return godot_return_type(ret)


# ---------------------------------------------------------------
# Method declarations — only handle** and const occtl_error_t**
# are stripped from method args; all other out-params stay as Ref<T> params.
# ---------------------------------------------------------------

def _is_stripped_out_param(p: CParameter, ret: str) -> bool:
    """True if this out-param should be REMOVED from the Godot method signature.
    These are handle** and const occtl_error_t** — they become return values."""
    if not is_out_param(p.type_name, p.name, ret):
        return False
    t = p.type_name.strip()
    base = _c_type_strip_ptr(t).strip()
    if base == "occtl_error_t" and t.endswith("**"):
        return True
    if t.endswith("**"):
        return True
    return False


def _method_args_decl(f: CFunction) -> str:
    ret = f.return_type.strip()
    kept_params = [p for p in f.params if not _is_stripped_out_param(p, ret)]
    if not kept_params:
        return "void"
    args = []
    for p in kept_params:
        t = p.type_name.strip()
        # Out-params (non-handle) use Ref<T> wrapper classes
        if is_out_param(t, p.name, ret):
            base = _c_type_strip_ptr(t).strip()
            wrapper_cls = _out_param_wrapper_class(base, t)
            if wrapper_cls:
                args.append(f"const Ref<{wrapper_cls}>& {p.name}")
                continue
        gt = godot_param_type(t)
        if gt in ("String", "Variant", "Array", "Dictionary", "PackedByteArray") or gt.startswith("Ref<"):
            args.append(f"const {gt}& {p.name}")
        else:
            args.append(f"{gt} {p.name}")
    return ", ".join(args)


def _method_arg_names(f: CFunction) -> str:
    ret = f.return_type.strip()
    kept_params = [p for p in f.params if not _is_stripped_out_param(p, ret)]
    return "".join(f', "{p.name}"' for p in kept_params)


def _method_defvals(f: CFunction) -> str:
    """Return DEFVAL(...) string for trailing nullable params."""
    ret = f.return_type.strip()
    kept = [p for p in f.params if not _is_stripped_out_param(p, ret)]
    nullable = DEFAULT_NULLABLE_PARAMS.get(f.name, set())
    defvals = []
    for p in kept:
        if p.name in nullable:
            defvals.append("DEFVAL(Variant())")
    if not defvals:
        return ""
    return ", " + ", ".join(defvals)


def _wrapper_class_name(header_include: str) -> str:
    stem = Path(header_include).stem
    parts = stem.replace("occtl_", "", 1).split("_")
    return "Occtl" + "".join(p.capitalize() for p in parts)


def _common_function_prefix(functions: list[CFunction]) -> str:
    if not functions:
        return ""
    names = [f.name for f in functions]
    prefix = names[0]
    for name in names[1:]:
        while not name.startswith(prefix):
            prefix = prefix[:-1]
            if not prefix:
                return ""
    if prefix and not prefix.endswith("_"):
        last_us = prefix.rfind("_")
        if last_us >= 0:
            prefix = prefix[:last_us + 1]
        else:
            prefix = ""
    return prefix


def _function_method_name(f: CFunction, all_functions: list[CFunction]) -> str:
    prefix = _common_function_prefix(all_functions)
    if prefix and f.name.startswith(prefix):
        return f.name[len(prefix):]
    return f.name


def _function_method_names(functions: list[CFunction]) -> dict[str, str]:
    return {f.name: _function_method_name(f, functions) for f in functions}


# ---------------------------------------------------------------
# Body generation
# ---------------------------------------------------------------

def _generate_out_param_copy_line(p: CParameter, local_var: str, indent: str = "    ") -> str:
    """Generate line to copy a C out-param value into a Godot wrapper ref."""
    t = p.type_name.strip()
    base = _c_type_strip_ptr(t).strip()
    resolved = _resolve_typedef(base)
    name = p.name if p.name else "out"
    wrapper_cls = _out_param_wrapper_class(base, t)
    if wrapper_cls is None:
        return ""
    if resolved in VALUE_STRUCT_TYPES:
        return f"{indent}if ({name}.is_valid()) {name}->copy_from_c({local_var});"
    if resolved in UINT64_ID_TYPES:
        return f"{indent}if ({name}.is_valid()) {name}->copy_from_c({local_var});"
    if resolved in OUT_PARAM_PRIM_TYPES or resolved in ENUM_TYPES:
        return f"{indent}if ({name}.is_valid()) {name}->copy_from_c({local_var});"
    if resolved in ("const char", "char"):
        return f"{indent}if ({name}.is_valid()) {name}->copy_from_c({local_var});"
    return ""


def _generate_body(f: CFunction, wrapper_name: str, parsed: ParsedHeader | None = None) -> str:
    ret = f.return_type.strip()
    out_params = [p for p in f.params if is_out_param(p.type_name, p.name, ret)]
    handle_out_params = [p for p in out_params if _is_direct_return_out_param(p)]
    non_handle_out_params = [p for p in out_params if not _is_direct_return_out_param(p)]
    lines = []
    ret_mapped = _func_return_type_mapped(f)

    # Special case: const occtl_error_t* return → Ref<OcctlError>
    if ret == "const occtl_error_t*":
        lines.append(f"    const occtl_error_t* _err = ::{f.name}();")
        lines.append("    if (!_err) return Ref<OcctlError>();")
        lines.append("    return OcctlError::from_c(*_err);")
        return "\n".join(lines)

    # Build call_args preserving C parameter order
    call_args = []
    c_func_name = f.name

    for p in f.params:
        t = p.type_name.strip()
        name = p.name if p.name else ""
        if is_out_param(t, p.name, ret):
            base = _c_type_strip_ptr(t).strip()
            if t.endswith("**"):
                # Handle** or const char** out-param
                if t == "const char**" or t == "const char * *":
                    local = f"_{name}_buf"
                    cap_param = None
                    for other in f.params:
                        if other.name != p.name and other.type_name.strip() == "size_t" and not is_out_param(other.type_name, other.name, ret):
                            cap_param = other
                            break
                    if cap_param:
                        cap_name = cap_param.name
                        lines.append(f"    std::vector<const char*> {local}(static_cast<size_t>({cap_name}));")
                        call_args.append(f"{local}.data()")
                    else:
                        local = f"_{name}_val"
                        lines.append(f"    const char* {local} = nullptr;")
                        call_args.append(f"&{local}")
                else:
                    local = f"_{name}_val"
                    resolved_base = _resolve_typedef(base)
                    if resolved_base == "occtl_error_t":
                        # const occtl_error_t** → return as Ref<OcctlError>
                        lines.append(f"    const {resolved_base}* {local} = nullptr;")
                        call_args.append(f"&{local}")
                    else:
                        lines.append(f"    {base}* {local} = nullptr;")
                        call_args.append(f"&{local}")
            elif base == "uint8_t":
                # uint8_t* buffer out-param
                buf_size = 16
                if parsed:
                    for c in parsed.constants:
                        if "WIRE_SIZE" in c.name or "BUFFER_SIZE" in c.name:
                            try:
                                buf_size = int(c.value.strip())
                            except ValueError:
                                pass
                local = f"_{name}_buf"
                lines.append(f"    uint8_t {local}[{buf_size}] = {{}};")
                call_args.append(local)
            else:
                local = f"_{name}_val"
                resolved = _resolve_typedef(base)
                if resolved in (VALUE_STRUCT_TYPES | UINT64_ID_TYPES | ENUM_TYPES | set(OUT_PARAM_PRIM_TYPES.keys())):
                    lines.append(f"    {resolved} {local} = {{}};")
                    call_args.append(f"&{local}")
                else:
                    lines.append(f"    {base} {local} = {{}};")
                    call_args.append(f"&{local}")
        else:
            # In-param
            t_stripped = re.sub(r'\s+(const|volatile)\s*$', '', t)
            if t_stripped.startswith("const ") and t_stripped.endswith("*") and not t_stripped.endswith("**"):
                base_raw = _c_type_strip_ptr(t_stripped).strip()
                base = re.sub(r'^(const|volatile)\s+', '', base_raw).strip()
                if base == "uint8_t":
                    lines.append(f"    const uint8_t* _{name}_c = {name}.ptr();")
                    call_args.append(f"_{name}_c")
                elif is_value_struct_type(base):
                    if f.name in DEFAULT_NULLABLE_PARAMS and p.name in DEFAULT_NULLABLE_PARAMS[f.name]:
                        base_no_const = base_raw.replace("const ", "", 1) if base_raw.startswith("const ") else base_raw
                        lines.append(f"    {base_no_const} _{name}_c = {{}};")
                        lines.append(f"    const {base_no_const}* _{name}_ptr = nullptr;")
                        lines.append(f"    if ({name}.is_valid()) {{ _{name}_c = {name}->to_c(); _{name}_ptr = &_{name}_c; }}")
                        call_args.append(f"_{name}_ptr")
                    else:
                        lines.append(f"    {base_raw} _{name}_c = {name}->to_c();")
                        call_args.append(f"&_{name}_c")
                elif base in HANDLE_TYPES:
                    call_args.append(f"reinterpret_cast<const {base}*>(static_cast<uintptr_t>({name}.is_valid() ? {name}->get_handle() : 0))")
                elif base in UINT64_ID_TYPES:
                    lines.append(f"    {base} _{name}_c = {{static_cast<uint64_t>({name})}};")
                    call_args.append(f"&_{name}_c")
                elif base == "char":
                    call_args.append(f"{name}.utf8().get_data()")
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
        lines.append(f"    occtl_status_t _status = ::{c_func_name}({', '.join(call_args)});")
    else:
        if ret == "void":
            lines.append(f"    ::{c_func_name}({', '.join(call_args)});")
        else:
            lines.append(f"    auto _result = ::{c_func_name}({', '.join(call_args)});")

    # Copy non-handle out-param values into Godot wrapper refs
    for p in non_handle_out_params:
        t = p.type_name.strip()
        base = _c_type_strip_ptr(t).strip()
        name = p.name if p.name else "out"
        if t == "const char**" or t == "const char * *":
            local = f"_{name}_buf"
            for other in f.params:
                ot = other.type_name.strip()
                if other.name != p.name and ot.endswith("*") and ot.rstrip("*") == "size_t" and is_out_param(ot, other.name, ret):
                    count_local = f"_{other.name}_val"
                    lines.append(f"    if ({name}.is_valid()) {name}->copy_from_c({local}.data(), {count_local});")
                    break
            else:
                lines.append(f"    if ({name}.is_valid()) {name}->copy_from_c({local});")
        elif base == "uint8_t":
            buf_size = 16
            if parsed:
                for c in parsed.constants:
                    if "WIRE_SIZE" in c.name or "BUFFER_SIZE" in c.name:
                        try:
                            buf_size = int(c.value.strip())
                        except ValueError:
                            pass
            lines.append(f"    if ({name}.is_valid()) {{")
            lines.append(f"        PackedByteArray _ba;")
            lines.append(f"        _ba.resize({buf_size});")
            lines.append(f"        for (int _i = 0; _i < {buf_size}; ++_i) _ba[_i] = _{name}_buf[_i];")
            lines.append(f"        {name}->copy_from_c(_ba);")
            lines.append(f"    }}")
        else:
            local = f"_{name}_val"
            copy_line = _generate_out_param_copy_line(p, local)
            if copy_line:
                lines.append(copy_line)

    # Build return
    if handle_out_params and _func_is_occtl_status(f):
        p = handle_out_params[0]
        base = _c_type_strip_ptr(p.type_name).strip()
        inner = re.sub(r'^(const|volatile)\s+', '', base.rstrip("* \t")).strip()
        local = f"_{p.name}_val"
        if inner in HANDLE_TYPES:
            cls = c_type_to_godot_class(base) + "Handle"
            lines.append(f"    if (_status != OCCTL_OK) {{ return Ref<{cls}>(); }}")
            lines.append(f"    if (!{local}) {{ return Ref<{cls}>(); }}")
            lines.append(f"    Ref<{cls}> _h;")
            lines.append(f"    _h.instantiate();")
            lines.append(f"    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>({local})));")
            lines.append(f"    return _h;")
        elif inner in UINT64_ID_TYPES:
            lines.append(f"    if (_status != OCCTL_OK) {{ return 0; }}")
            lines.append(f"    return static_cast<int64_t>({local}->bits);")
        else:
            lines.append(f"    return static_cast<int>(_status);")
    elif handle_out_params and not _func_is_occtl_status(f):
        # Non-status C return with handle** out-param (unusual)
        lines.append(f"    return static_cast<int64_t>(reinterpret_cast<uintptr_t>(_{handle_out_params[0].name}_val));")
    elif _func_is_occtl_status(f):
        lines.append("    return static_cast<int>(_status);")
    elif ret == "void":
        pass
    else:
        lines.append(f"    return {_c_to_godot_return(ret, '_result')};")

    if not lines:
        lines.append("    return {};")
    return "\n".join(lines)


def _c_to_godot_return(c_type: str, expr: str) -> str:
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


# ---------------------------------------------------------------
# Header generation
# ---------------------------------------------------------------

def generate_wrapper_header(
    parsed: ParsedHeader,
    value_type_includes: list[str],
) -> str:
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
    for c in _filtered_constants(parsed.constants):
        ret = _constant_godot_return_type(c, parsed.constants)
        if ret != "int":
            lines.append(f"    {ret} const_{c.name}(); // NOLINT")
    # Enum values are registered via BIND_ENUM_CONSTANT; no methods needed.
    method_names = _function_method_names(functions)
    for f in functions:
        ret_mapped = _func_return_type_mapped(f)
        args_decl = _method_args_decl(f)
        mname = method_names[f.name]
        lines.append(f"    {ret_mapped} {mname}({args_decl}); // NOLINT")
    if not functions and not parsed.constants and not parsed.enums:
        lines.append("    void _unused();")
    lines.extend([
        "};",
        "",
        f"#endif // {guard}",
        "",
    ])
    return "\n".join(lines)


def _constant_value_resolve(v: str, consts: list[CConstant]) -> str:
    """Resolve a constant value through #define reference chains."""
    seen = set()
    while True:
        v_stripped = v.strip()
        if v_stripped in seen:
            break
        seen.add(v_stripped)
        found = None
        for c in consts:
            if c.name == v_stripped:
                found = c.value.strip()
                break
        if found is None or found == v_stripped:
            break
        v = found
    return v


def _constant_godot_return_type(c: CConstant, consts: list[CConstant] | None = None) -> str:
    v = c.value.strip()
    # Resolve through #define chains if we have a constant lookup
    if consts is not None:
        v = _constant_value_resolve(v, consts)
    while v.startswith("(") and v.endswith(")"):
        v = v[1:-1].strip()
    # Strip C integer suffixes: u, U, l, L, ul, UL, ll, LL, ull, ULL
    clean = v.rstrip("uUlL ")
    v_lower = v.lower()
    if v_lower in ("true", "false"):
        return "bool"
    if "." in v or ("e" in v_lower and any(d in v for d in "0123456789")):
        return "double"
    if v_lower.startswith("0x") or v_lower.startswith("0X"):
        return "int"
    try:
        int(clean)
        return "int"
    except ValueError:
        pass
    if any(c in v for c in "+-*/"):
        return "double" if ("." in v or v_lower.startswith("pi")) else "int"
    if v_lower in ("null", "nullptr"):
        return "int64_t"
    return "int64_t"


# ---------------------------------------------------------------
# Source generation
# ---------------------------------------------------------------

def generate_wrapper_source(
    parsed: ParsedHeader,
) -> str:
    cls = _wrapper_class_name(parsed.header_include)
    functions = parsed.functions

    has_vector = any(
        p.type_name.strip() == "char*" or p.type_name.strip() in ("const char**", "const char * *")
        for f in functions
        for p in f.params
    )

    lines = [
        f'#include "{cls}.h"',
        "",
        f'#include "occtl/{parsed.header_include}"',
        "",
    ]
    if has_vector:
        lines.append("#include <vector>")
        lines.append("")

    lines.append(f"void {cls}::_bind_methods() {{")
    for c in _filtered_constants(parsed.constants):
        ret = _constant_godot_return_type(c, parsed.constants)
        if ret == "int":
            lines.append(f"    BIND_CONSTANT({c.name});")
        else:
            lines.append(f'    godot::ClassDB::bind_method(godot::D_METHOD("const_{c.name}"), &{cls}::const_{c.name});')
    for ev in (
        ev for enum in parsed.enums for ev in enum.values
    ):
        lines.append(f"    BIND_CONSTANT({ev.name});")
    method_names = _function_method_names(functions)
    for f in functions:
        mname = method_names[f.name]
        defvals = _method_defvals(f)
        lines.append(f'    godot::ClassDB::bind_method(godot::D_METHOD("{mname}"{_method_arg_names(f)}), &{cls}::{mname}{defvals});')
    if not functions and not parsed.constants and not parsed.enums:
        lines.append(f"    godot::ClassDB::bind_method(godot::D_METHOD(\"_unused\"), &{cls}::_unused);")
    lines.append("}")
    lines.append("")

    for c in _filtered_constants(parsed.constants):
        ret = _constant_godot_return_type(c, parsed.constants)
        if ret != "int":
            body = _generate_constant_body(c, parsed.constants)
            lines.append(f"{ret} {cls}::const_{c.name}() {{ // NOLINT")
            lines.append(f"    {body}")
            lines.append("}")
            lines.append("")

    method_names = _function_method_names(functions)
    for f in functions:
        ret_mapped = _func_return_type_mapped(f)
        args_decl = _method_args_decl(f)
        mname = method_names[f.name]
        lines.append(f"{ret_mapped} {cls}::{mname}({args_decl}) {{ // NOLINT")
        body = _generate_body(f, cls, parsed)
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


def _generate_constant_body(c: CConstant, consts: list[CConstant] | None = None) -> str:
    v = c.value.strip()
    ret = _constant_godot_return_type(c, consts)
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
    cls = _wrapper_class_name(parsed.header_include)
    methods = []

    for c in parsed.constants:
        ret = _constant_godot_return_type(c, parsed.constants)
        if ret in ("int", "bool"):
            methods.append(f'\t\t<constant name="{escape(c.name)}" value="{escape(str(c.value))}">')
            methods.append(f"\t\t\t{c.doc_comment or f'Constant for #define {c.name}'}.")
            methods.append("\t\t</constant>")
        else:
            methods.append(f'\t\t<method name="const_{escape(c.name)}">')
            methods.append(f'\t\t\t<return type="{ret}" />')
            methods.append("\t\t\t<description>")
            methods.append(f"\t\t\t\t{c.doc_comment or f'Constant wrapper for #define {c.name}'}.")
            methods.append("\t\t\t</description>")
            methods.append("\t\t</method>")

    for enum in parsed.enums:
        for ev in enum.values:
            methods.append(f'\t\t<constant name="{escape(ev.name)}" value="{escape(str(ev.value))}">')
            methods.append(f"\t\t\tEnum value = {ev.value}.")
            methods.append("\t\t</constant>")

    method_names = _function_method_names(parsed.functions)
    for f in parsed.functions:
        ret_mapped = _func_return_type_mapped(f)
        mname = method_names[f.name]
        methods.append(f'\t\t<method name="{escape(mname)}">')
        if ret_mapped != "void":
            methods.append(f'\t\t\t<return type="{ret_mapped}" />')
        ret = f.return_type.strip()
        kept_params = [p for p in f.params if not _is_stripped_out_param(p, ret)]
        for i, p in enumerate(kept_params):
            gt = godot_param_type(p.type_name.strip())
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

    for c in _filtered_constants(parsed.constants):
        lines.append(f"static func test_{c.name}() -> String:")
        ret = _constant_godot_return_type(c, parsed.constants)
        if ret == "int":
            lines.append(f"    var v = {cls}.{c.name}")
        else:
            mname = f"const_{c.name}"
            lines.append(f"    var v = {cls}.new().{mname}()")
            lines.append("    if v == null: return \"Failed: {c.name} returned null\"")
        lines.append('    return ""')
        lines.append("")

    for enum in parsed.enums:
        for ev in enum.values:
            lines.append(f"static func test_{ev.name}() -> String:")
            lines.append(f"    var v = {cls}.{ev.name}")
            lines.append("    if v < 0: return \"Failed: enum value negative\"")
            lines.append('    return ""')
            lines.append("")

    return "\n".join(lines)
