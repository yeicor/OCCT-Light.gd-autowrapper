"""Generate Godot RefCounted wrapper classes for OCCT-Light C header functions.

Given a parsed C header, generates a Godot class that wraps every C function,
constant, and enum value as bound methods.
"""

import re
from pathlib import Path
from xml.sax.saxutils import escape

from parser import (
    CConstant,
    CEnum,
    CEnumValue,
    CField,
    CFunction,
    CParameter,
    CStruct,
    ParsedHeader,
)
from type_map import (
    CALLBACK_TYPES,
    CPP_TO_GODOT_TYPE,
    ENUM_TYPES,
    HANDLE_TYPES,
    INPUT_PTR_SIZE_ARRAY_TYPES,
    UINT64_ID_TYPES,
    VALUE_STRUCT_TYPES,
    _resolve_typedef,
    c_type_to_godot_class,
    godot_param_type,
    godot_return_type,
    input_ptr_size_godot_type,
    is_auto_handle_type,
    is_callback_type,
    is_input_ptr_size_type,
    is_opaque_ptr_t_type,
    is_out_param,
    is_value_struct_type,
    param_type_to_variant_type,
)

# C type → short human-readable description for doc generation
_C_TYPE_DOC_DESC: dict[str, str] = {
    "occtl_node_id_t": "node",
    "occtl_uid_t": "UID",
    "occtl_ref_uid_t": "reference UID",
    "occtl_ref_id_t": "reference ID",
    "occtl_rep_uid_t": "representation UID",
    "occtl_joint_id_t": "joint",
}


def _c_type_strip_ptr(t: str) -> str:
    t = re.sub(r"\s+(const|volatile)\s*$", "", t)
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
        if "{" in val:
            continue
        if val.startswith("__"):
            continue
        result.append(c)
    return result


# ---------------------------------------------------------------
# Callback param detection — (function_ptr, void* user_data) pairs
# ---------------------------------------------------------------

CALLBACK_CALLEE_NAMES = {"visitor", "callback", "handler", "fn", "func", "callable"}


def _is_callback_param(p: CParameter) -> bool:
    return is_callback_type(p.type_name.strip()) or (
        p.type_name.strip() in ("void*",) and p.name in ("user_data", "data", "context")
    )


def _find_callback_userdata_pairs(
    params: list[CParameter],
) -> list[tuple[int, int]]:
    """Find all (callback_param_index, user_data_param_index) pairs.
    A callback param is a CALLBACK_TYPES type; the immediately following
    void* is its user_data.  Only the first pair is used for method sig
    simplification; remaining pairs stay as raw ints."""
    pairs = []
    i = 0
    while i < len(params) - 1:
        if is_callback_type(params[i].type_name.strip()):
            next_t = params[i + 1].type_name.strip()
            if next_t == "void*":
                pairs.append((i, i + 1))
                i += 2
                continue
        i += 1
    return pairs


BRIDGE_FUNCTION_NAMES: dict[str, str] = {
    "occtl_node_visitor_t": "_occtl_node_visitor_bridge",
    "occtl_ref_visitor_t": "_occtl_ref_visitor_bridge",
    "occtl_rep_visitor_t": "_occtl_rep_visitor_bridge",
    "occtl_metadata_visitor_t": "_occtl_metadata_visitor_bridge",
}

CALLBACK_BRIDGE_SOURCE: dict[str, str] = {
    "occtl_node_visitor_t": """
OCCTL_CALL occtl_status_t _occtl_node_visitor_bridge(occtl_node_id_t node, void* user_data) {
    auto* ctx = static_cast<_CallbackContext*>(user_data);
    Variant _result = ctx->callable.call(static_cast<int64_t>(node.bits));
    return static_cast<occtl_status_t>(static_cast<int64_t>(_result));
}
""",
    "occtl_ref_visitor_t": """
OCCTL_CALL occtl_status_t _occtl_ref_visitor_bridge(occtl_ref_id_t ref, void* user_data) {
    auto* ctx = static_cast<_CallbackContext*>(user_data);
    Variant _result = ctx->callable.call(static_cast<int64_t>(ref.bits));
    return static_cast<occtl_status_t>(static_cast<int64_t>(_result));
}
""",
    "occtl_rep_visitor_t": """
OCCTL_CALL occtl_status_t _occtl_rep_visitor_bridge(occtl_rep_id_t rep, void* user_data) {
    auto* ctx = static_cast<_CallbackContext*>(user_data);
    Variant _result = ctx->callable.call(static_cast<int64_t>(rep.bits));
    return static_cast<occtl_status_t>(static_cast<int64_t>(_result));
}
""",
    "occtl_metadata_visitor_t": """
OCCTL_CALL occtl_status_t _occtl_metadata_visitor_bridge(const char* key, void* user_data) {
    auto* ctx = static_cast<_CallbackContext*>(user_data);
    Variant _result = ctx->callable.call(String(key));
    return static_cast<occtl_status_t>(static_cast<int64_t>(_result));
}
""",
}


def _callback_types_needed(functions: list[CFunction]) -> set[str]:
    """Return set of callback type names needed by any function."""
    needed = set()
    for f in functions:
        for cb_idx, _ in _find_callback_userdata_pairs(f.params):
            needed.add(f.params[cb_idx].type_name.strip())
    return needed


def _bridge_function_name(callback_type: str) -> str:
    return BRIDGE_FUNCTION_NAMES.get(callback_type, f"_{callback_type}_bridge")


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

# Buffer element C types → Godot PackedArray return type for two-call pattern
TWO_CALL_PACKED_RETURN: dict[str, str] = {
    "occtl_node_id_t": "PackedInt64Array",
    "occtl_uid_t": "PackedInt64Array",
    "occtl_ref_uid_t": "PackedInt64Array",
    "occtl_ref_id_t": "PackedInt64Array",
    "occtl_rep_uid_t": "PackedInt64Array",
    "occtl_rep_id_t": "PackedInt64Array",
    "occtl_joint_id_t": "PackedInt64Array",
    "int64_t": "PackedInt64Array",
    "double": "PackedFloat64Array",
    "int32_t": "PackedInt32Array",
    "uint8_t": "PackedByteArray",
    "uint32_t": "PackedInt32Array",
}

# Two-call buffer param name suffixes for detection
TWO_CALL_BUF_SUFFIXES = (
    "_buf",
    "_nodes",
    "_uids",
    "_colors",
    "_wires",
    "_tags",
    "_issues",
    "_joints",
    "_data",
    "_keys",
    "_rgba",
    "_count",
    "_required",
    "_size",
    "buf",
    "name_buf",
)
TWO_CALL_CAP_NAMES = {"cap", "capacity", "bufsize", "name_buf_size"}
TWO_CALL_COUNT_NAMES = {"out_count", "out_size", "out_required", "out_name_required"}


def _is_two_call_trailing_triplet(params: list, n: int) -> tuple[int, str]:
    """Check if params[n-3:n] matches (buf_ptr, size_t, size_t*) pattern
    where buf_ptr points to a packed-array-compatible type.
    Returns (buffer_index, base_c_type) or (-1, '')."""
    if n < 3:
        return -1, ""
    p0 = params[n - 3]
    p1 = params[n - 2]
    p2 = params[n - 1]
    t0 = p0.type_name.strip()
    t1 = p1.type_name.strip()
    t2 = p2.type_name.strip()
    if not (t0.endswith("*") and not t0.endswith("**")):
        return -1, ""
    if t1 != "size_t":
        return -1, ""
    if t2 != "size_t*":
        return -1, ""
    base0 = _c_type_strip_ptr(t0).strip()
    if base0 not in TWO_CALL_PACKED_RETURN:
        return -1, ""
    return n - 3, base0


def _is_two_call_string_triplet(params: list, n: int) -> tuple[int, str]:
    """Check if params[n-3:n] matches (char* buf, size_t, size_t*) pattern.
    Returns (buffer_index, 'char') or (-1, '')."""
    if n < 3:
        return -1, ""
    p0 = params[n - 3]
    p1 = params[n - 2]
    p2 = params[n - 1]
    t0 = p0.type_name.strip()
    t1 = p1.type_name.strip()
    t2 = p2.type_name.strip()
    base = _c_type_strip_ptr(t0).strip()
    if base == "char" and t0.endswith("*") and not t0.endswith("**"):
        if t1 == "size_t" and t2 == "size_t*":
            return n - 3, "char"
    return -1, ""


def _is_two_call_string_array_triplet(params: list, n: int) -> tuple[int, str]:
    """Check if params[n-3:n] matches (const char** buf, size_t, size_t*) pattern
    where buf is a pointer-to-pointer to char (array of C strings).
    Returns (buffer_index, 'const_char_ptr') or (-1, '')."""
    if n < 3:
        return -1, ""
    p0 = params[n - 3]
    p1 = params[n - 2]
    p2 = params[n - 1]
    t0 = p0.type_name.strip()
    t1 = p1.type_name.strip()
    t2 = p2.type_name.strip()
    if t0 in ("const char**", "const char * *"):
        if t1 == "size_t" and t2 == "size_t*":
            return n - 3, "const_char_ptr"
    return -1, ""


def _is_two_call_struct_triplet(params: list, n: int) -> tuple[int, str]:
    """Check if params[n-3:n] matches (struct_t* buf, size_t, size_t*) pattern.
    Returns (buffer_index, struct_type_name) or (-1, '')."""
    if n < 3:
        return -1, ""
    p0 = params[n - 3]
    p1 = params[n - 2]
    p2 = params[n - 1]
    t0 = p0.type_name.strip()
    t1 = p1.type_name.strip()
    t2 = p2.type_name.strip()
    base = _c_type_strip_ptr(t0).strip()
    if is_value_struct_type(base) and t0.endswith("*") and not t0.endswith("**"):
        if t1 == "size_t" and t2 == "size_t*":
            return n - 3, base
    return -1, ""


def _find_leading_buffers(params: list, triplet_start: int) -> list[tuple[int, str]]:
    """Find consecutive numeric buffer pointer params before the two-call triplet.
    Value struct pointers before a triplet are scalar out-params (pre-allocated Ref<T>),
    not arrays — only packed-output types appear as leading buffers.
    Returns list of (index, base_c_type)."""
    result = []
    i = triplet_start - 1
    while i >= 0:
        p = params[i]
        t = p.type_name.strip()
        if t.endswith("*") and not t.endswith("**"):
            base = _c_type_strip_ptr(t).strip()
            if base in TWO_CALL_PACKED_RETURN:
                result.insert(0, (i, base))
                i -= 1
                continue
        break
    return result


def _is_two_call_buffer_func(f: CFunction) -> bool:
    """Detect trailing (ptr buf, size_t cap, size_t* out_count) two-call pattern.
    Handles regular IDs, char*, const char**, and value struct* buffers."""
    params = f.params
    n = len(params)
    if n < 3:
        return False
    idx, base = _is_two_call_trailing_triplet(params, n)
    if idx >= 0:
        return True
    idx, base = _is_two_call_string_triplet(params, n)
    if idx >= 0:
        return True
    idx, base = _is_two_call_string_array_triplet(params, n)
    if idx >= 0:
        return True
    idx, base = _is_two_call_struct_triplet(params, n)
    if idx >= 0:
        return True
    return False


def _get_two_call_buffer_arrays(f: CFunction) -> list[tuple[str, str, str]]:
    """Return list of (buffer_param_name, buffer_c_type, godot_return_type)
    for all buffers in a two-call function. Includes leading parallel buffers."""
    params = f.params
    n = len(params)
    arrays = []

    # Find the trailing triplet (try all patterns)
    idx, base = _is_two_call_trailing_triplet(params, n)
    if idx < 0:
        idx, base = _is_two_call_string_triplet(params, n)
    if idx < 0:
        idx, base = _is_two_call_string_array_triplet(params, n)
    if idx < 0:
        idx, base = _is_two_call_struct_triplet(params, n)
    if idx < 0:
        return arrays

    # Leading parallel buffers — only for packed/struct trailing triplets.
    # String/string-array trailing triplet means leading ptrs are scalar out-params, not arrays.
    leading = []
    if base not in ("char", "const_char_ptr"):
        leading = _find_leading_buffers(params, idx)
    for li, lb in leading:
        pname = params[li].name
        if lb in TWO_CALL_PACKED_RETURN:
            arrays.append((pname, lb, TWO_CALL_PACKED_RETURN[lb]))

    # The trailing buffer itself
    tname = params[idx].name
    if base in TWO_CALL_PACKED_RETURN:
        arrays.append((tname, base, TWO_CALL_PACKED_RETURN[base]))
    elif is_value_struct_type(base):
        cls = c_type_to_godot_class(base)
        arrays.append((tname, base, f"Array[Ref[{cls}]]"))
    elif base == "char":
        arrays.append((tname, "char", "String"))
    elif base == "const_char_ptr":
        arrays.append((tname, "const char*", "PackedStringArray"))
    else:
        arrays.append((tname, base, "PackedInt64Array"))

    return arrays


def _two_call_buffer_return_type(f: CFunction) -> str:
    """Determine the C++ return type for a two-call buffer function."""
    arrays = _get_two_call_buffer_arrays(f)
    if not arrays:
        return "void"
    if len(arrays) == 1:
        r = arrays[0][2]
        if r.startswith("Array["):
            return "Array"
        return r
    # Multiple buffers → return Dictionary with all arrays
    return "Dictionary"


def _two_call_buffer_doc_return_type(f: CFunction) -> str:
    """Determine the GDScript return type string for doc XML."""
    arrays = _get_two_call_buffer_arrays(f)
    if not arrays:
        return "void"
    if len(arrays) == 1:
        return arrays[0][2]
    return "Dictionary"


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


def _find_const_view_pairs(f: CFunction) -> list[tuple[int, int]]:
    """Find (const T** ptr_idx, size_t* count_idx) pairs for
    view/allocation patterns where T is a value struct or uint64_id type.
    The count param must follow the ptr param.
    Returns list of (ptr_param_index, count_param_index)."""
    pairs: list[tuple[int, int]] = []
    params = f.params
    for i, p in enumerate(params):
        t = p.type_name.strip()
        if not (t.endswith("**") and not t.endswith("***")):
            continue
        base = _c_type_strip_ptr(t).strip()
        inner = re.sub(r"^(const|volatile)\s+", "", base.rstrip("* \t")).strip()
        # Skip types already handled by other mechanisms
        if inner == "char" or inner == "occtl_error_t" or inner in HANDLE_TYPES:
            continue
        if not (is_value_struct_type(inner) or inner in UINT64_ID_TYPES):
            continue
        # Look for following size_t* count param
        for j in range(i + 1, len(params)):
            ot = params[j].type_name.strip()
            if ot == "size_t*" and is_out_param(
                ot, params[j].name, f.return_type.strip()
            ):
                pairs.append((i, j))
                break
    return pairs


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


# ---------------------------------------------------------------
# Function classification
# ---------------------------------------------------------------


def _func_is_occtl_status(f: CFunction) -> bool:
    return f.return_type.strip() == "occtl_status_t"


def _func_return_type_mapped(f: CFunction) -> str:
    ret = f.return_type.strip()

    # Two-call buffer pattern → PackedArray / Dictionary / String / Array return type
    if _is_two_call_buffer_func(f):
        return _two_call_buffer_return_type(f)

    out_params = [p for p in f.params if is_out_param(p.type_name, p.name, ret)]

    # const occtl_error_t* → Ref<OcctlError>
    if ret == "const occtl_error_t*":
        return "Ref<OcctlError>"

    # const char* → String
    if ret == "const char*":
        return "String"

    # ** out-params returned directly (first such param wins)
    handle_outs = [p for p in out_params if _is_direct_return_out_param(p)]
    non_handle_outs = [p for p in out_params if not _is_direct_return_out_param(p)]

    if handle_outs:
        p = handle_outs[0]
        base = _c_type_strip_ptr(p.type_name).strip()
        inner = re.sub(r"^(const|volatile)\s+", "", base.rstrip("* \t")).strip()
        if inner in HANDLE_TYPES or is_auto_handle_type(inner):
            return f"Ref<{c_type_to_godot_class(base)}Handle>"
        # Single const char** → returns String (single C string from double-ptr)
        if inner == "char":
            return "String"
        # const T** view pairs return Array of Ref<T>
        view_pairs = _find_const_view_pairs(f)
        if view_pairs:
            return "Array"
        raise ValueError(
            f"_func_return_type_mapped: unknown double-ptr out-param type "
            f"'{p.type_name.strip()}' (inner={inner!r}) in function {f.name}"
        )

    # No handle out-params → return mapped C return type
    if ret == "void":
        return "void"
    if _func_is_occtl_status(f):
        return "int"
    return godot_return_type(ret)


# ---------------------------------------------------------------
# String + Size pairing — detect const char* + size_t pairs
# that should be collapsed into a single String parameter.
# ---------------------------------------------------------------

# Suffixes for size params that follow a string parameter
_STRING_SIZE_SUFFIXES = {"len", "length", "size", "count"}


def _is_string_len_pair(f: CFunction, string_idx: int, size_idx: int) -> bool:
    """Check if params[string_idx] (const char*) and params[size_idx] (size_t)
    form a string+length pair that should be collapsed."""
    p_str = f.params[string_idx]
    p_sz = f.params[size_idx]
    t_str = p_str.type_name.strip()
    t_sz = p_sz.type_name.strip()
    # The string param must be const char* (NOT mutable char* which is an output buffer)
    if not t_str.startswith("const "):
        return False
    base_str = _c_type_strip_ptr(t_str).strip()
    if re.sub(r"^(const|volatile)\s+", "", base_str).strip() != "char":
        return False
    if not t_str.endswith("*") or t_str.endswith("**"):
        return False
    # The size param must be size_t (non-pointer scalar)
    if t_sz != "size_t":
        return False
    # The size param should not be an out-param
    if is_out_param(t_sz, p_sz.name, f.return_type.strip()):
        return False
    # Further guard: make sure the size param name suggests it's related to the string
    sname = p_str.name.lower()
    szname = p_sz.name.lower()
    # Size param name should be the string name + a suffix like Len, Size, Count
    if szname.startswith(sname) and szname != sname:
        suffix = szname[len(sname) :]
        if suffix.lower() in _STRING_SIZE_SUFFIXES:
            return True
    # Alternative pattern: szname is exactly sname + one of the recognized suffixes
    for suf in _STRING_SIZE_SUFFIXES:
        if szname == sname + suf:
            return True
    return False


def _find_string_len_pairs(f: CFunction) -> list[tuple[int, int]]:
    """Find all (string_idx, size_idx) pairs in the function params."""
    pairs = []
    params = f.params
    i = 0
    while i < len(params) - 1:
        p = params[i]
        t = p.type_name.strip()
        base = _c_type_strip_ptr(t).strip()
        inner = re.sub(r"^(const|volatile)\s+", "", base).strip()
        if inner == "char" and t.endswith("*") and not t.endswith("**"):
            # Check if the following param is a size_t that pairs with this string
            for j in range(i + 1, min(i + 3, len(params))):
                if _is_string_len_pair(f, i, j):
                    pairs.append((i, j))
                    i = j + 1
                    break
            else:
                i += 1
        else:
            i += 1
    return pairs


def _is_in_string_len_pair(f: CFunction, p_idx: int) -> bool:
    """Check if param at p_idx is part of a string+length pair."""
    for str_idx, size_idx in _find_string_len_pairs(f):
        if p_idx == str_idx or p_idx == size_idx:
            return True
    return False


# ---------------------------------------------------------------
# Input pointer+size array detection
# Detect (const T* data, size_t count) pairs and collapse them
# into a single array parameter (PackedInt64Array, etc.).
# ---------------------------------------------------------------


def _find_input_ptr_size_pairs(f: CFunction) -> list[tuple[int, int]]:
    """Find all (ptr_idx, size_idx) pairs where ptr is an array input
    and size is the element count.

    Matches consecutive: const <element_type>* <name>, size_t <count>
    where element_type is in INPUT_PTR_SIZE_ARRAY_TYPES.
    """
    pairs = []
    params = f.params
    i = 0
    while i < len(params) - 1:
        p = params[i]
        t = p.type_name.strip()
        # Must be const <T>*  (non-const, single ptr)
        if not t.startswith("const "):
            i += 1
            continue
        if not t.endswith("*") or t.endswith("**"):
            i += 1
            continue
        base = _c_type_strip_ptr(t).strip()
        inner = re.sub(r"^(const|volatile)\s+", "", base).strip()
        if not is_input_ptr_size_type(inner):
            i += 1
            continue
        # Next param must be size_t (non-pointer)
        if i + 1 >= len(params):
            i += 1
            continue
        next_p = params[i + 1]
        if next_p.type_name.strip() != "size_t":
            i += 1
            continue
        # Size param must not be an out-param
        if is_out_param(next_p.type_name, next_p.name, f.return_type.strip()):
            i += 1
            continue
        # Found a pair
        pairs.append((i, i + 1))
        i += 2
        continue
    return pairs


def _is_in_input_ptr_size_pair(f: CFunction, idx: int) -> bool:
    """Check if param at idx is part of an input pointer+size pair."""
    for ptr_idx, size_idx in _find_input_ptr_size_pairs(f):
        if idx == ptr_idx or idx == size_idx:
            return True
    return False


def _input_ptr_size_element_type(f: CFunction, ptr_idx: int) -> str:
    """Get the C element type for the pointer at ptr_idx."""
    t = f.params[ptr_idx].type_name.strip()
    base = _c_type_strip_ptr(t).strip()
    inner = re.sub(r"^(const|volatile)\s+", "", base).strip()
    return inner


# ---------------------------------------------------------------
# Method declarations — handle**, const T** view pairs, and
# const occtl_error_t** are stripped from method args; all other
# out-params stay as Ref<T> params.
# ---------------------------------------------------------------


def _is_stripped_out_param(p: CParameter, ret: str) -> bool:
    """True if this out-param should be REMOVED from the Godot method signature.
    These are handle**, const occtl_error_t** — they become return values.
    size_t* count params from const view pairs are also stripped via
    _build_kept_params which skips them explicitly."""
    if not is_out_param(p.type_name, p.name, ret):
        return False
    t = p.type_name.strip()
    base = _c_type_strip_ptr(t).strip()
    if base == "occtl_error_t" and t.endswith("**"):
        return True
    if t.endswith("**"):
        return True
    return False


def _is_buffer_triplet_param(f: CFunction, p: CParameter) -> bool:
    """Check if param is part of a trailing two-call buffer triplet
    OR a leading parallel buffer param."""
    if not _is_two_call_buffer_func(f):
        return False
    n = len(f.params)
    # The trailing triplet
    if p is f.params[n - 3] or p is f.params[n - 2] or p is f.params[n - 1]:
        return True
    # Leading parallel buffer params (only for packed/struct triplets)
    idx, base = _is_two_call_trailing_triplet(f.params, n)
    if idx < 0:
        idx, base = _is_two_call_string_triplet(f.params, n)
    if idx < 0:
        idx, base = _is_two_call_struct_triplet(f.params, n)
    if idx >= 0 and base != "char":
        leading = _find_leading_buffers(f.params, idx)
        for li, _ in leading:
            if p is f.params[li]:
                return True
    return False


def _get_string_len_indices(string_len_pairs: list) -> set:
    """Return set of all indices that are part of string+size pairs."""
    indices = set()
    for str_idx, size_idx in string_len_pairs:
        indices.add(str_idx)
        indices.add(size_idx)
    return indices


def _build_kept_params(
    f: CFunction, ret: str, string_len_pairs: list, string_len_indices: set
) -> list:
    """Build the list of params to keep, preserving original order.

    Strips out-params (handle**), buffer triplet params, size params
    from string+size pairs, size params from input ptr+size pairs,
    and size_t* count params from const view pairs.
    """
    input_ptr_size_pairs = _find_input_ptr_size_pairs(f)
    input_ptr_size_indices = {size_idx for _, size_idx in input_ptr_size_pairs}

    # Find const view pair count indices to strip
    const_view_pairs = _find_const_view_pairs(f)
    const_view_count_indices = {count_idx for _, count_idx in const_view_pairs}
    const_view_ptr_indices = {ptr_idx for ptr_idx, _ in const_view_pairs}

    kept = []
    for i, p in enumerate(f.params):
        if i in const_view_count_indices:
            continue  # skip count params from const view pairs
        if i in const_view_ptr_indices:
            continue  # skip ptr params from const view pairs (handled by _is_stripped_out_param too)
        if _is_stripped_out_param(p, ret):
            continue
        if _is_buffer_triplet_param(f, p):
            continue
        # Skip size params from input ptr+size pairs
        if i in input_ptr_size_indices:
            continue  # skip size params entirely
        if i in string_len_indices:
            # Check if this is the SIZE part of a string+size pair
            is_size = False
            for str_idx, size_idx in string_len_pairs:
                if i == size_idx:
                    is_size = True
                    break
            if is_size:
                continue  # skip size params entirely
            # String param - keep at original position
            kept.append(p)
            continue
        kept.append(p)
    return kept


def _method_args_decl(f: CFunction) -> str:
    ret = f.return_type.strip()
    string_len_pairs = _find_string_len_pairs(f)
    string_len_indices = _get_string_len_indices(string_len_pairs)
    kept_params = _build_kept_params(f, ret, string_len_pairs, string_len_indices)
    callback_pairs = _find_callback_userdata_pairs(f.params)
    # Build set of param indices to exclude (user_data part of callback pairs)
    exclude_indices = {ud_idx for _, ud_idx in callback_pairs}
    if not (
        kept_params
        and any(
            p
            for i, p in enumerate(kept_params)
            if id(p) not in (id(f.params[ei]) for ei in exclude_indices)
        )
    ):
        if callback_pairs:
            return "const Callable& callable"
        return "void"
    args = []
    for p in kept_params:
        t = p.type_name.strip()
        # Check if this param is part of a callback pair
        is_cb = False
        is_ud = False
        for cb_idx, ud_idx in callback_pairs:
            if p is f.params[cb_idx]:
                is_cb = True
                break
            if p is f.params[ud_idx]:
                is_ud = True
                break
        if is_cb:
            args.append("const Callable& callable")
            continue
        if is_ud:
            continue  # skip user_data param
        # Input pointer+size pairs use PackedArray type
        input_ptr_size_pairs = _find_input_ptr_size_pairs(f)
        is_input_ptr = False
        for ptr_idx, _size_idx in input_ptr_size_pairs:
            if p is f.params[ptr_idx]:
                is_input_ptr = True
                break
        if is_input_ptr:
            elem_type = _input_ptr_size_element_type(f, f.params.index(p))
            arr_type = input_ptr_size_godot_type(elem_type)
            if arr_type:
                if arr_type == "Array":
                    args.append(f"const Array& {p.name}")
                else:
                    args.append(f"const {arr_type}& {p.name}")
                continue

        # Out-params (non-handle) use Ref<T> wrapper classes
        if is_out_param(t, p.name, ret):
            base = _c_type_strip_ptr(t).strip()
            wrapper_cls = _out_param_wrapper_class(base, t)
            if wrapper_cls:
                args.append(f"const Ref<{wrapper_cls}>& {p.name}")
                continue
        gt = godot_param_type(t)
        if gt in (
            "String",
            "Variant",
            "Array",
            "Dictionary",
            "PackedByteArray",
        ) or gt.startswith("Ref<"):
            args.append(f"const {gt}& {p.name}")
        else:
            args.append(f"{gt} {p.name}")
    return ", ".join(args)


def _method_arg_names(f: CFunction) -> str:
    ret = f.return_type.strip()
    string_len_pairs = _find_string_len_pairs(f)
    string_len_indices = _get_string_len_indices(string_len_pairs)
    kept_params = _build_kept_params(f, ret, string_len_pairs, string_len_indices)
    callback_pairs = _find_callback_userdata_pairs(f.params)
    exclude_indices = {ud_idx for _, ud_idx in callback_pairs}
    names = []
    for p in kept_params:
        in_pair = False
        for cb_idx, ud_idx in callback_pairs:
            if p is f.params[cb_idx]:
                names.append(', "callable"')
                in_pair = True
                break
            if p is f.params[ud_idx]:
                in_pair = True  # skip user_data in D_METHOD
                break
        if not in_pair:
            names.append(f', "{p.name}"')
    return "".join(names)


def _method_defvals(f: CFunction) -> str:
    """Return DEFVAL(...) string for trailing nullable params
    and parameters with C default values.

    Any const value-struct pointer param is automatically nullable."""
    ret = f.return_type.strip()
    string_len_pairs = _find_string_len_pairs(f)
    string_len_indices = _get_string_len_indices(string_len_pairs)
    kept = _build_kept_params(f, ret, string_len_pairs, string_len_indices)
    nullable = set(DEFAULT_NULLABLE_PARAMS.get(f.name, set()))
    defvals = []
    for p in kept:
        # Auto-detect nullable const value-struct pointer params
        t = p.type_name.strip()
        if t.startswith("const ") and t.endswith("*") and not t.endswith("**"):
            base_raw = _c_type_strip_ptr(t).strip()
            base = re.sub(r"^(const|volatile)\s+", "", base_raw).strip()
            if is_value_struct_type(base) or p.name in nullable:
                defvals.append("DEFVAL(Variant())")
                continue
        if p.name in nullable:
            defvals.append("DEFVAL(Variant())")
        elif p.default_value:
            gd_val = _c_default_to_godot(p.default_value)
            defvals.append(f"DEFVAL({gd_val})")
    if not defvals:
        return ""
    return ", " + ", ".join(defvals)


def _c_default_to_godot(c_val: str) -> str:
    """Convert a C default value expression to a Godot-compatible
    DEFVAL expression."""
    v = c_val.strip()
    # Remove C-style casts
    v = re.sub(r"\(\w+\s*\**\)", "", v).strip()
    # NULL / nullptr → Variant()
    if v.lower() in ("null", "nullptr", "0"):
        return "Variant()"
    # true/false → Godot bool literal
    if v.lower() in ("true", "false"):
        return v.lower()
    # String literals
    if v.startswith('"') and v.endswith('"'):
        return v
    # Constants (will evaluate at compile time in C++)
    if v.isupper() and "_" in v:
        return v
    # Numeric values — strip C suffixes (u, l, f, etc.)
    v_clean = v.rstrip("uUlLfF ")
    try:
        # Try parsing as number
        float(v_clean)
        return v_clean
    except ValueError:
        pass
    # Fall back to the raw value
    return v


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
            prefix = prefix[: last_us + 1]
        else:
            prefix = ""
    return prefix


def _function_method_name(f: CFunction, all_functions: list[CFunction]) -> str:
    prefix = _common_function_prefix(all_functions)
    if prefix and f.name.startswith(prefix):
        return f.name[len(prefix) :]
    return f.name


def _function_method_names(functions: list[CFunction]) -> dict[str, str]:
    return {f.name: _function_method_name(f, functions) for f in functions}


# ---------------------------------------------------------------
# Body generation
# ---------------------------------------------------------------


def _generate_out_param_copy_line(
    p: CParameter, local_var: str, indent: str = "    "
) -> str:
    """Generate line to copy a C out-param value into a Godot wrapper ref."""
    t = p.type_name.strip()
    base = _c_type_strip_ptr(t).strip()
    resolved = _resolve_typedef(base)
    name = p.name if p.name else "out"
    wrapper_cls = _out_param_wrapper_class(base, t)
    if wrapper_cls is None:
        raise ValueError(
            f"No out-param wrapper class for type '{t}' (base='{base}', resolved='{_resolve_typedef(base)}'). "
            f"Function has an out-param '{name}' with an unsupported C type. "
            f"Either add the type to OUT_PARAM_PRIM_TYPES, VALUE_STRUCT_TYPES, or provide a wrapper class."
        )
    if resolved in VALUE_STRUCT_TYPES:
        return f"{indent}if ({name}.is_valid()) {name}->copy_from_c({local_var});"
    if resolved in UINT64_ID_TYPES:
        return f"{indent}if ({name}.is_valid()) {name}->copy_from_c({local_var});"
    if resolved in OUT_PARAM_PRIM_TYPES or resolved in ENUM_TYPES:
        return f"{indent}if ({name}.is_valid()) {name}->copy_from_c({local_var});"
    if resolved in ("const char", "char"):
        return f"{indent}if ({name}.is_valid()) {name}->copy_from_c({local_var});"
    return ""


def _generate_body(
    f: CFunction, wrapper_name: str, parsed: ParsedHeader | None = None
) -> str:
    ret = f.return_type.strip()
    out_params = [p for p in f.params if is_out_param(p.type_name, p.name, ret)]
    handle_out_params = [p for p in out_params if _is_direct_return_out_param(p)]
    non_handle_out_params = [
        p for p in out_params if not _is_direct_return_out_param(p)
    ]
    lines = []
    ret_mapped = _func_return_type_mapped(f)

    # Const view pairs: (const T** ptr, size_t* count) → return Array of Ref<T>
    const_view_pairs = _find_const_view_pairs(f)
    const_view_ptr_indices = {ptr_idx for ptr_idx, _ in const_view_pairs}
    const_view_count_indices = {count_idx for _, count_idx in const_view_pairs}
    const_view_ptr_to_count = dict(const_view_pairs)

    # Two-call buffer pattern (trailing ptr, size_t, size_t*)
    if _is_two_call_buffer_func(f):
        n_params = len(f.params)
        # Identify trailing triplet and leading buffers
        buf_idx, base0 = _is_two_call_trailing_triplet(f.params, n_params)
        is_string = False
        is_string_array = False
        is_struct_arr = False
        if buf_idx < 0:
            buf_idx, base0 = _is_two_call_string_triplet(f.params, n_params)
            is_string = buf_idx >= 0
        if buf_idx < 0:
            buf_idx, base0 = _is_two_call_string_array_triplet(f.params, n_params)
            is_string_array = buf_idx >= 0
        if buf_idx < 0:
            buf_idx, base0 = _is_two_call_struct_triplet(f.params, n_params)
            is_struct_arr = buf_idx >= 0
        cap_idx = n_params - 2
        cnt_idx = n_params - 1
        cnt_name = f.params[cnt_idx].name

        # Only detect leading buffers when trailing triplet is packed or struct.
        # String/string-array trailing triplet means leading ptrs are scalar out-params.
        leading = []
        if not is_string and not is_string_array:
            leading = _find_leading_buffers(f.params, buf_idx)

        # Collect all buffer param indices: leading + trailing triplet buffer
        buffer_indices = [li for li, _ in leading] + [buf_idx]

        # Detect string buffer in leading positions too
        leading_string_count = sum(1 for _, lb in leading if lb == "char")
        is_returning_string = (
            is_string and len(buffer_indices) == 1 and leading_string_count == 0
        )

        arrays = _get_two_call_buffer_arrays(f)
        single_packed = len(arrays) == 1 and arrays[0][2].startswith("Packed")
        single_string = is_returning_string
        single_string_array = is_string_array and len(buffer_indices) == 1
        single_struct = len(arrays) == 1 and arrays[0][2].startswith("Array[Ref[")
        return_dict = len(arrays) > 1

        # Determine return type string for error returns
        ret_type_str = ret_mapped if ret_mapped != "void" else "PackedInt64Array"

        # Declare count variable
        lines.append(f"    size_t _{cnt_name}_cnt = 0;")

        # Build call args with nullptr for buffer, 0 for cap, &cnt for count
        call_args_null = []
        call_args_buf = []
        string_convs = []  # deferred CharString declarations
        string_len_pairs = _find_string_len_pairs(f)
        for j, p in enumerate(f.params):
            name = p.name if p.name else ""
            # Check if this param is the SIZE part of a string+size pair
            is_size_in_string_pair = False
            for str_idx, size_idx in string_len_pairs:
                if j == size_idx:
                    str_name = f.params[str_idx].name
                    size_arg = f"static_cast<size_t>({str_name}.utf8().length())"
                    call_args_null.append(size_arg)
                    call_args_buf.append(size_arg)
                    is_size_in_string_pair = True
                    break
            if is_size_in_string_pair:
                continue
            if j in buffer_indices:
                # Buffer param: nullptr in first call, data() in second
                call_args_null.append("nullptr")
                call_args_buf.append(f"_{name}_buf.data()")
            elif j == cap_idx:
                call_args_null.append("0")
                call_args_buf.append(f"_{cnt_name}_cnt")
            elif j == cnt_idx:
                call_args_null.append(f"&_{cnt_name}_cnt")
                call_args_buf.append(f"&_{cnt_name}_cnt")
            elif is_out_param(p.type_name, p.name, ret):
                base = _c_type_strip_ptr(p.type_name).strip()
                resolved = _resolve_typedef(base)
                if resolved in (
                    VALUE_STRUCT_TYPES
                    | UINT64_ID_TYPES
                    | ENUM_TYPES
                    | set(OUT_PARAM_PRIM_TYPES.keys())
                ):
                    lines.append(f"    {resolved} _{name}_val = {{}};")
                elif resolved in ("const char", "char"):
                    lines.append(f"    const char* _{name}_val = nullptr;")
                else:
                    lines.append(f"    {base} _{name}_val = {{}};")
                call_args_null.append(f"&_{name}_val")
                call_args_buf.append(f"&_{name}_val")
            else:
                # Regular in-param - generate its conversion inline
                t_stripped = re.sub(r"\s+(const|volatile)\s*$", "", p.type_name.strip())
                if (
                    t_stripped.startswith("const ")
                    and t_stripped.endswith("*")
                    and not t_stripped.endswith("**")
                ):
                    base_r = _c_type_strip_ptr(t_stripped).strip()
                    b = re.sub(r"^(const|volatile)\s+", "", base_r).strip()
                    if is_value_struct_type(b):
                        base_no_const = (
                            base_r.replace("const ", "", 1)
                            if base_r.startswith("const ")
                            else base_r
                        )
                        lines.append(f"    {base_no_const} _{name}_c = {{}};")
                        lines.append(
                            f"    const {base_no_const}* _{name}_ptr = nullptr;"
                        )
                        lines.append(
                            f"    if ({name}.is_valid()) {{ _{name}_c = {name}->to_c(); _{name}_ptr = &_{name}_c; }}"
                        )
                        call_args_null.append(f"_{name}_ptr")
                        call_args_buf.append(f"_{name}_ptr")
                    elif b in HANDLE_TYPES:
                        arg = f"reinterpret_cast<const {b}*>(static_cast<uintptr_t>({name}.is_valid() ? {name}->get_handle() : 0))"
                        call_args_null.append(arg)
                        call_args_buf.append(arg)
                    elif b == "char":
                        cs_name = f"_{name}_cs"
                        string_convs.append(
                            f"    godot::CharString {cs_name} = {name}.utf8();"
                        )
                        call_args_null.append(f"{cs_name}.get_data()")
                        call_args_buf.append(f"{cs_name}.get_data()")
                    elif b == "void":
                        arg = f"reinterpret_cast<const void*>(static_cast<uintptr_t>(static_cast<int64_t>({name})))"
                        call_args_null.append(arg)
                        call_args_buf.append(arg)
                    else:
                        # ----- FALLTHROUGH HARDENED (two-call, const pointer) -----
                        raise ValueError(
                            f"[_generate_body/two-call] Unknown const pointer param: {f.name}.{name}, "
                            f"t={t!r}, base={b!r}"
                        )
                elif t_stripped in UINT64_ID_TYPES:
                    call_args_null.append(
                        f"{t_stripped}{{static_cast<uint64_t>({name})}}"
                    )
                    call_args_buf.append(
                        f"{t_stripped}{{static_cast<uint64_t>({name})}}"
                    )
                elif t_stripped == "occtl_status_t":
                    call_args_null.append(f"static_cast<{t_stripped}>({name})")
                    call_args_buf.append(f"static_cast<{t_stripped}>({name})")
                elif is_opaque_ptr_t_type(t_stripped):
                    call_args_null.append(
                        f"reinterpret_cast<{t_stripped}>(static_cast<uintptr_t>(static_cast<int64_t>({name})))"
                    )
                    call_args_buf.append(
                        f"reinterpret_cast<{t_stripped}>(static_cast<uintptr_t>(static_cast<int64_t>({name})))"
                    )
                else:
                    t_clean = re.sub(r"\s+(const|volatile)\s*$", "", t_stripped)
                    if t_clean.endswith("*") and not t_clean.endswith("**"):
                        base = _c_type_strip_ptr(t_clean).strip()
                        if base in HANDLE_TYPES:
                            arg = f"reinterpret_cast<{base}*>(static_cast<uintptr_t>({name}.is_valid() ? {name}->get_handle() : 0))"
                            call_args_null.append(arg)
                            call_args_buf.append(arg)
                        elif base == "char":
                            cs_name = f"_{name}_cs"
                            string_convs.append(
                                f"    godot::CharString {cs_name} = {name}.utf8();"
                            )
                            call_args_null.append(f"{cs_name}.get_data()")
                            call_args_buf.append(f"{cs_name}.get_data()")
                        elif base == "void":
                            arg = f"reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<int64_t>({name})))"
                            call_args_null.append(arg)
                            call_args_buf.append(arg)
                        else:
                            # ----- FALLTHROUGH HARDENED (two-call, non-const pointer) -----
                            raise ValueError(
                                f"[_generate_body/two-call] Unknown non-const pointer param: {f.name}.{name}, "
                                f"t={t!r}, base={base!r}"
                            )
                    elif t_stripped in ENUM_TYPES:
                        call_args_null.append(f"static_cast<{t_stripped}>({name})")
                        call_args_buf.append(f"static_cast<{t_stripped}>({name})")
                    elif t_stripped in (
                        "double",
                        "float",
                        "int32_t",
                        "uint32_t",
                        "int64_t",
                        "uint64_t",
                        "size_t",
                        "uint16_t",
                        "uint8_t",
                        "bool",
                        "int",
                    ):
                        call_args_null.append(f"static_cast<{t_stripped}>({name})")
                        call_args_buf.append(f"static_cast<{t_stripped}>({name})")
                    else:
                        # ----- FALLTHROUGH HARDENED (two-call, general else) -----
                        raise ValueError(
                            f"[_generate_body/two-call] Unknown param type: {f.name}.{name}, "
                            f"t={t_stripped!r}"
                        )

            # Emit deferred string conversions before first call
        for conv in string_convs:
            lines.append(conv)

        # First call with nullptr to get count
        call_null_str = ", ".join(call_args_null)
        if _func_is_occtl_status(f):
            lines.append(f"    occtl_status_t _err = ::{f.name}({call_null_str});")
            lines.append(
                f"    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) {{ return {ret_type_str}(); }}"
            )
        else:
            lines.append(f"    ::{f.name}({call_null_str});")

        # Allocate buffers for ALL buffer params
        for bi in buffer_indices:
            bname = f.params[bi].name
            btype = f.params[bi].type_name.strip()
            bbase = _c_type_strip_ptr(btype).strip()
            if bbase == "char":
                lines.append(
                    f"    std::vector<char> _{bname}_buf(_{cnt_name}_cnt + 1);"
                )
            elif bbase == "uint8_t":
                lines.append(f"    std::vector<uint8_t> _{bname}_buf(_{cnt_name}_cnt);")
            elif bbase in ("double", "int32_t", "int64_t", "uint32_t", "size_t"):
                lines.append(f"    std::vector<{bbase}> _{bname}_buf(_{cnt_name}_cnt);")
            elif is_value_struct_type(bbase):
                lines.append(
                    f"    std::vector<{bbase}> _{bname}_buf(static_cast<size_t>(_{cnt_name}_cnt));"
                )
            elif is_string_array or bbase == "const char":
                # const char** — array of C string pointers
                lines.append(
                    f"    std::vector<const char*> _{bname}_buf(_{cnt_name}_cnt);"
                )
            else:
                lines.append(f"    std::vector<{bbase}> _{bname}_buf(_{cnt_name}_cnt);")

        # Second call with buffers
        call_buf_str = ", ".join(call_args_buf)
        if _func_is_occtl_status(f):
            lines.append(f"    _err = ::{f.name}({call_buf_str});")

        # Copy back non-buffer out-param values to user's Ref<T> wrappers
        for p in non_handle_out_params:
            if _is_buffer_triplet_param(f, p):
                continue
            name = p.name if p.name else "out"
            line = _generate_out_param_copy_line(p, f"_{name}_val")
            if line:
                lines.append(line)

        # Convert to Godot return type(s)
        if single_packed:
            buf_name = f.params[buf_idx].name
            pk_type = arrays[0][2]
            lines.append(f"    {pk_type} _result;")
            lines.append(f"    _result.resize(static_cast<int64_t>(_{cnt_name}_cnt));")
            if pk_type == "PackedInt64Array":
                if base0 != "int64_t":
                    lines.append(
                        f"    for (size_t _i = 0; _i < _{cnt_name}_cnt; _i++) _result[static_cast<int64_t>(_i)] = static_cast<int64_t>(_{buf_name}_buf[_i].bits);"
                    )
                else:
                    lines.append(
                        f"    for (size_t _i = 0; _i < _{cnt_name}_cnt; _i++) _result[static_cast<int64_t>(_i)] = _{buf_name}_buf[_i];"
                    )
            elif pk_type == "PackedFloat64Array":
                lines.append(
                    f"    for (size_t _i = 0; _i < _{cnt_name}_cnt; _i++) _result[static_cast<int64_t>(_i)] = _{buf_name}_buf[_i];"
                )
            elif pk_type == "PackedInt32Array":
                lines.append(
                    f"    for (size_t _i = 0; _i < _{cnt_name}_cnt; _i++) _result[static_cast<int64_t>(_i)] = _{buf_name}_buf[_i];"
                )
            elif pk_type == "PackedByteArray":
                lines.append(
                    f"    for (size_t _i = 0; _i < _{cnt_name}_cnt; _i++) _result[static_cast<int64_t>(_i)] = _{buf_name}_buf[_i];"
                )
            lines.append("    return _result;")
        elif single_string:
            buf_name = f.params[buf_idx].name
            lines.append(f"    return godot::String(_{buf_name}_buf.data());")
        elif single_string_array:
            buf_name = f.params[buf_idx].name
            lines.append("    PackedStringArray _result;")
            lines.append(f"    _result.resize(static_cast<int64_t>(_{cnt_name}_cnt));")
            lines.append(
                f"    for (size_t _i = 0; _i < _{cnt_name}_cnt; _i++) _result[static_cast<int64_t>(_i)] = godot::String(_{buf_name}_buf[_i]);"
            )
            lines.append("    return _result;")
        elif single_struct:
            buf_name = f.params[buf_idx].name
            struct_cls = arrays[0][2].replace("Array[Ref[", "").rstrip("]")
            lines.append(f"    Array _result;")
            lines.append(f"    _result.resize(static_cast<int64_t>(_{cnt_name}_cnt));")
            lines.append(f"    for (size_t _i = 0; _i < _{cnt_name}_cnt; _i++) {{")
            lines.append(f"        Ref<{struct_cls}> _item;")
            lines.append(f"        _item.instantiate();")
            lines.append(f"        _item->copy_from_c(_{buf_name}_buf[_i]);")
            lines.append(f"        _result[static_cast<int64_t>(_i)] = _item;")
            lines.append(f"    }}")
            lines.append("    return _result;")
        elif return_dict:

            def _dict_key(n):
                return re.sub(r"^out_", "", n).lstrip("_")

            lines.append("    Dictionary _result;")
            for aname, atype, aret in arrays:
                buf_entry = next(
                    (bi for bi in buffer_indices if f.params[bi].name == aname), buf_idx
                )
                if aret.startswith("Packed"):
                    aname_cpp = _dict_key(aname)
                    lines.append(f"    {aret} _{aname_cpp};")
                    lines.append(
                        f"    _{aname_cpp}.resize(static_cast<int64_t>(_{cnt_name}_cnt));"
                    )
                    if aret == "PackedInt64Array":
                        if atype != "int64_t":
                            lines.append(
                                f"    for (size_t _i = 0; _i < _{cnt_name}_cnt; _i++) _{aname_cpp}[static_cast<int64_t>(_i)] = static_cast<int64_t>(_{aname}_buf[_i].bits);"
                            )
                        else:
                            lines.append(
                                f"    for (size_t _i = 0; _i < _{cnt_name}_cnt; _i++) _{aname_cpp}[static_cast<int64_t>(_i)] = _{aname}_buf[_i];"
                            )
                    else:
                        lines.append(
                            f"    for (size_t _i = 0; _i < _{cnt_name}_cnt; _i++) _{aname_cpp}[static_cast<int64_t>(_i)] = _{aname}_buf[_i];"
                        )
                    lines.append(f'    _result["{aname_cpp}"] = _{aname_cpp};')
                elif aret.startswith("Array[Ref["):
                    struct_cls = aret.replace("Array[Ref[", "").rstrip("]")
                    aname_cpp = _dict_key(aname)
                    lines.append(f"    Array _{aname_cpp};")
                    lines.append(
                        f"    _{aname_cpp}.resize(static_cast<int64_t>(_{cnt_name}_cnt));"
                    )
                    lines.append(
                        f"    for (size_t _i = 0; _i < _{cnt_name}_cnt; _i++) {{"
                    )
                    lines.append(f"        Ref<{struct_cls}> _item;")
                    lines.append(f"        _item.instantiate();")
                    lines.append(f"        _item->copy_from_c(_{aname}_buf[_i]);")
                    lines.append(
                        f"        _{aname_cpp}[static_cast<int64_t>(_i)] = _item;"
                    )
                    lines.append(f"    }}")
                    lines.append(f'    _result["{aname_cpp}"] = _{aname_cpp};')
                elif aret == "String":
                    aname_cpp = _dict_key(aname)
                    lines.append(
                        f'    _result["{aname_cpp}"] = godot::String(_{aname}_buf.data());'
                    )
            lines.append("    return _result;")
        else:
            lines.append(f"    return {ret_type_str}();")
        return "\n".join(lines)

    # Special case: const occtl_error_t* return → Ref<OcctlError>
    if ret == "const occtl_error_t*":
        lines.append(f"    const occtl_error_t* _err = ::{f.name}();")
        lines.append("    if (!_err) return Ref<OcctlError>();")
        lines.append("    return OcctlError::from_c(*_err);")
        return "\n".join(lines)

    # Check for callback params → need context struct
    callback_pairs = _find_callback_userdata_pairs(f.params)
    if callback_pairs:
        lines.append("    _CallbackContext _ctx;")
        lines.append("    _ctx.callable = callable;")

    # Detect input ptr+size pairs for array-like parameters
    input_ptr_size_pairs = _find_input_ptr_size_pairs(f)
    input_ptr_size_indices = {ptr_idx for ptr_idx, _ in input_ptr_size_pairs}
    input_size_indices = {size_idx for _, size_idx in input_ptr_size_pairs}

    # Build call_args preserving C parameter order
    call_args = []
    c_func_name = f.name

    for p in f.params:
        t = p.type_name.strip()
        name = p.name if p.name else ""

        # Callback pair handling: replace callback with bridge function,
        # void* user_data with &_ctx
        cb_handled = False
        for cb_idx, ud_idx in callback_pairs:
            if p is f.params[cb_idx]:
                cb_type = f.params[cb_idx].type_name.strip()
                call_args.append(_bridge_function_name(cb_type))
                cb_handled = True
                break
            if p is f.params[ud_idx]:
                call_args.append("&_ctx")
                cb_handled = True
                break
        if cb_handled:
            continue

        # Skip count params from const view pairs (already handled with ptr)
        p_idx = f.params.index(p)
        if p_idx in const_view_count_indices:
            continue

        # Input ptr+size pair handling
        if p is not None:
            if p_idx in input_ptr_size_indices:
                # This is the pointer param of an input ptr+size pair
                # Generate: reinterpret_cast<const elem_type*>(name.ptr())
                elem_type = _input_ptr_size_element_type(f, p_idx)
                arr_type = input_ptr_size_godot_type(elem_type)
                if arr_type in (
                    "PackedInt64Array",
                    "PackedFloat64Array",
                    "PackedInt32Array",
                    "PackedFloat32Array",
                    "PackedByteArray",
                ):
                    if elem_type in UINT64_ID_TYPES:
                        # occtl_node_id_t etc. are structs with a bits field
                        # The PackedInt64Array stores int64_t, we reinterpret_cast to the C struct
                        call_args.append(
                            f"reinterpret_cast<const {elem_type}*>(static_cast<const void*>({name}.ptr()))"
                        )
                    else:
                        call_args.append(f"{name}.ptr()")
                else:
                    # Fallback for Array types
                    call_args.append(
                        f"reinterpret_cast<const {elem_type}*>(static_cast<const void*>({name}.ptr()))"
                    )
                continue
            if p_idx in input_size_indices:
                # This is the size param of an input ptr+size pair
                # Find the corresponding pointer param name
                ptr_name = ""
                for ptr_idx, size_idx in input_ptr_size_pairs:
                    if p_idx == size_idx:
                        ptr_name = f.params[ptr_idx].name
                        break
                call_args.append(f"static_cast<size_t>({ptr_name}.size())")
                continue

        # Check if this param is the SIZE part of a string+size pair
        string_len_pairs = _find_string_len_pairs(f)
        is_size_in_string_pair = False
        for str_idx, size_idx in string_len_pairs:
            if p is f.params[size_idx]:
                # Replace the size argument with the string's actual length
                str_name = f.params[str_idx].name
                call_args.append(f"static_cast<size_t>({str_name}.utf8().length())")
                is_size_in_string_pair = True
                break
        if is_size_in_string_pair:
            continue

        if is_out_param(t, p.name, ret):
            base = _c_type_strip_ptr(t).strip()
            if t.endswith("**"):
                # View pair: const T** ptr + size_t* count → Array of Ref<T>
                if p_idx in const_view_ptr_indices:
                    count_idx = const_view_ptr_to_count[p_idx]
                    count_name = f.params[count_idx].name
                    inner_type = re.sub(r"^(const|volatile)\s+", "", base).strip()
                    lines.append(f"    const {inner_type}* _{name}_ptr = nullptr;")
                    lines.append(f"    size_t _{count_name}_cnt = 0;")
                    call_args.append(f"&_{name}_ptr")
                    call_args.append(f"&_{count_name}_cnt")
                    continue  # count param handled here, skip when loop reaches it
                # Handle** or const char** out-param
                if t == "const char**" or t == "const char * *":
                    local = f"_{name}_buf"
                    cap_param = None
                    for other in f.params:
                        if (
                            other.name != p.name
                            and other.type_name.strip() == "size_t"
                            and not is_out_param(other.type_name, other.name, ret)
                        ):
                            cap_param = other
                            break
                    if cap_param:
                        cap_name = cap_param.name
                        lines.append(
                            f"    std::vector<const char*> {local}(static_cast<size_t>({cap_name}));"
                        )
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
                    elif resolved_base in HANDLE_TYPES or is_auto_handle_type(
                        resolved_base
                    ):
                        # Handle** → passed as pointer-to-pointer, handled in return section
                        lines.append(f"    {base}* {local} = nullptr;")
                        call_args.append(f"&{local}")
                    else:
                        # ----- HARDENED: Unknown ** type would silently drop data -----
                        raise ValueError(
                            f"[_generate_body] Unknown double-ptr out-param type: "
                            f"{f.name}.{name}, t={t!r}, base={base!r}, "
                            f"resolved={_resolve_typedef(base)!r}"
                        )
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
                if resolved in (
                    VALUE_STRUCT_TYPES
                    | UINT64_ID_TYPES
                    | ENUM_TYPES
                    | set(OUT_PARAM_PRIM_TYPES.keys())
                ):
                    # Initialize versioned structs with their init function
                    # so struct_version is set correctly.
                    # Only call init if the function exists in the parsed
                    # header (check by constructing the expected name).
                    # Initialize versioned structs with their init function
                    # so struct_version is set correctly.
                    # Only call init if the function exists in the parsed
                    # header (check by constructing the expected name).
                    _needs_init = (
                        resolved.startswith("occtl_")
                        and resolved.endswith("_t")
                        and resolved in VALUE_STRUCT_TYPES
                        and parsed is not None
                        and any(
                            fn.name == f"occtl_{resolved[6:-2]}_init"
                            for fn in parsed.functions
                        )
                    )
                    if _needs_init:
                        _fn = f"occtl_{resolved[6:-2]}_init"
                        lines.append(f"    {resolved} {local} = {{}};")
                        lines.append(f"    ::{_fn}(&{local});")
                    else:
                        lines.append(f"    {resolved} {local} = {{}};")
                    call_args.append(f"&{local}")
                else:
                    lines.append(f"    {base} {local} = {{}};")
                    call_args.append(f"&{local}")
        else:
            # In-param
            t_stripped = re.sub(r"\s+(const|volatile)\s*$", "", t)
            if (
                t_stripped.startswith("const ")
                and t_stripped.endswith("*")
                and not t_stripped.endswith("**")
            ):
                base_raw = _c_type_strip_ptr(t_stripped).strip()
                base = re.sub(r"^(const|volatile)\s+", "", base_raw).strip()
                if base == "uint8_t":
                    lines.append(f"    const uint8_t* _{name}_c = {name}.ptr();")
                    call_args.append(f"_{name}_c")
                elif is_value_struct_type(base):
                    base_no_const = (
                        base_raw.replace("const ", "", 1)
                        if base_raw.startswith("const ")
                        else base_raw
                    )
                    lines.append(f"    {base_no_const} _{name}_c = {{}};")
                    lines.append(f"    const {base_no_const}* _{name}_ptr = nullptr;")
                    lines.append(
                        f"    if ({name}.is_valid()) {{ _{name}_c = {name}->to_c(); _{name}_ptr = &_{name}_c; }}"
                    )
                    call_args.append(f"_{name}_ptr")
                elif base in HANDLE_TYPES:
                    call_args.append(
                        f"reinterpret_cast<const {base}*>(static_cast<uintptr_t>({name}.is_valid() ? {name}->get_handle() : 0))"
                    )
                elif base in UINT64_ID_TYPES:
                    lines.append(
                        f"    {base} _{name}_c = {{static_cast<uint64_t>({name})}};"
                    )
                    call_args.append(f"&_{name}_c")
                elif base == "char":
                    call_args.append(f"{name}.utf8().get_data()")
                elif base == "void":
                    call_args.append(
                        f"reinterpret_cast<{base_raw}*>(static_cast<uintptr_t>(static_cast<int64_t>({name})))"
                    )
                else:
                    # ----- FALLTHROUGH HARDENED -----
                    raise ValueError(
                        f"[_generate_body] Unknown const pointer in-param type: param={f.name}.{name}, "
                        f"c_type={t!r}, base={base!r}"
                    )
            elif t in UINT64_ID_TYPES:
                call_args.append(f"{t}{{static_cast<uint64_t>({name})}}")
            elif t == "occtl_status_t":
                call_args.append(f"static_cast<{t}>({name})")
            elif is_opaque_ptr_t_type(t):
                call_args.append(
                    f"reinterpret_cast<{t}>(static_cast<uintptr_t>(static_cast<int64_t>({name})))"
                )
            elif is_value_struct_type(t):
                call_args.append(f"{name}->to_c()")
            elif t == "char*":
                local = f"_{name}_c"
                lines.append(f"    godot::CharString _{name}_cs = {name}.utf8();")
                lines.append(
                    f"    std::vector<char> _{name}_buf(_{name}_cs.get_data(), _{name}_cs.get_data() + _{name}_cs.length() + 1);"
                )
                lines.append(f"    char* {local} = _{name}_buf.data();")
                call_args.append(local)
            elif t in (
                "double",
                "float",
                "int32_t",
                "uint32_t",
                "int64_t",
                "uint64_t",
                "size_t",
                "uint16_t",
                "uint8_t",
                "bool",
                "int",
            ):
                call_args.append(f"static_cast<{t}>({name})")
            else:
                if t in ENUM_TYPES:
                    call_args.append(f"static_cast<{t}>({name})")
                    continue
                t_clean = re.sub(r"\s+(const|volatile)\s*$", "", t)
                if t_clean.endswith("*"):
                    base = _c_type_strip_ptr(t_clean).strip()
                    if base in HANDLE_TYPES:
                        # For _free functions, use release() to prevent double-free
                        # in the handle's destructor.
                        _is_free_fn = f.name.endswith("_free")
                        if _is_free_fn:
                            call_args.append(
                                f"reinterpret_cast<{base}*>(static_cast<uintptr_t>({name}.is_valid() ? {name}->release() : 0))"
                            )
                        else:
                            call_args.append(
                                f"reinterpret_cast<{base}*>(static_cast<uintptr_t>({name}.is_valid() ? {name}->get_handle() : 0))"
                            )
                    elif base == "char":
                        lines.append(
                            f"    godot::CharString _{name}_cs = {name}.utf8();"
                        )
                        lines.append(
                            f"    std::vector<char> _{name}_buf(_{name}_cs.get_data(), _{name}_cs.get_data() + _{name}_cs.length() + 1);"
                        )
                        lines.append(f"    char* _{name}_c = _{name}_buf.data();")
                        call_args.append(f"_{name}_c")
                    elif base == "void":
                        call_args.append(
                            f"reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<int64_t>({name})))"
                        )
                    elif is_opaque_ptr_t_type(base):
                        call_args.append(
                            f"reinterpret_cast<{base}*>(static_cast<uintptr_t>(static_cast<int64_t>({name})))"
                        )
                    elif t_clean.startswith("const "):
                        # ----- FALLTHROUGH HARDENED -----
                        raise ValueError(
                            f"[_generate_body] Unknown const pointer in-param (2nd pass): {f.name}.{name}, "
                            f"t={t!r}, base={base!r}"
                        )
                    else:
                        # ----- FALLTHROUGH HARDENED -----
                        raise ValueError(
                            f"[_generate_body] Unknown non-const pointer in-param (2nd pass): {f.name}.{name}, "
                            f"t={t!r}, base={base!r}"
                        )
                else:
                    # ----- FALLTHROUGH HARDENED -----
                    raise ValueError(
                        f"[_generate_body] Unknown non-pointer in-param: {f.name}.{name}, "
                        f"t={t!r}"
                    )

    # Call the C function
    if _func_is_occtl_status(f):
        lines.append(
            f"    occtl_status_t _status = ::{c_func_name}({', '.join(call_args)});"
        )
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
                if (
                    other.name != p.name
                    and ot.endswith("*")
                    and ot.rstrip("*") == "size_t"
                    and is_out_param(ot, other.name, ret)
                ):
                    count_local = f"_{other.name}_val"
                    lines.append(
                        f"    if ({name}.is_valid()) {name}->copy_from_c({local}.data(), {count_local});"
                    )
                    break
            else:
                lines.append(
                    f"    if ({name}.is_valid()) {name}->copy_from_c({local});"
                )
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
            lines.append(
                f"        for (int _i = 0; _i < {buf_size}; ++_i) _ba[_i] = _{name}_buf[_i];"
            )
            lines.append(f"        {name}->copy_from_c(_ba);")
            lines.append(f"    }}")
        else:
            local = f"_{name}_val"
            copy_line = _generate_out_param_copy_line(p, local)
            if copy_line:
                lines.append(copy_line)

    # Build return
    if const_view_pairs and _func_is_occtl_status(f):
        # const T** view pair → return Array of Ref<T> (or PackedArray for id types)
        for ptr_idx, cnt_idx in const_view_pairs:
            p = f.params[ptr_idx]
            cnt = f.params[cnt_idx]
            ptr_name = p.name if p.name else "out"
            cnt_name = cnt.name
        inner_type = re.sub(
            r"^(const|volatile)\s+", "", _c_type_strip_ptr(p.type_name.strip()).strip()
        ).strip()
        view_resolved = _resolve_typedef(inner_type)
        if _func_is_occtl_status(f):
            lines.append(f"    if (_status != OCCTL_OK) {{ return Array(); }}")
        if view_resolved in UINT64_ID_TYPES:
            # PackedInt64Array for id types (occtl_rep_id_t, occtl_uid_t, etc.)
            lines.append(f"    PackedInt64Array _result;")
            lines.append(f"    _result.resize(static_cast<int64_t>(_{cnt_name}_cnt));")
            lines.append(
                f"    for (size_t _i = 0; _i < _{cnt_name}_cnt; _i++) {{ _result[static_cast<int64_t>(_i)] = static_cast<int64_t>(_{ptr_name}_ptr[_i].bits); }}"
            )
            lines.append(f"    return _result;")
        elif is_value_struct_type(view_resolved):
            cls = c_type_to_godot_class(view_resolved)
            lines.append(f"    Array _result;")
            lines.append(f"    _result.resize(static_cast<int64_t>(_{cnt_name}_cnt));")
            lines.append(f"    for (size_t _i = 0; _i < _{cnt_name}_cnt; _i++) {{")
            lines.append(f"        Ref<{cls}> _item;")
            lines.append(f"        _item.instantiate();")
            lines.append(f"        _item->copy_from_c(_{ptr_name}_ptr[_i]);")
            lines.append(f"        _result[static_cast<int64_t>(_i)] = _item;")
            lines.append(f"    }}")
            lines.append(f"    return _result;")
        else:
            raise ValueError(
                f"[_generate_body] View pair inner type '{view_resolved}' not supported "
                f"in function {f.name}"
            )
    elif handle_out_params and _func_is_occtl_status(f):
        p = handle_out_params[0]
        base = _c_type_strip_ptr(p.type_name).strip()
        inner = re.sub(r"^(const|volatile)\s+", "", base.rstrip("* \t")).strip()
        local = f"_{p.name}_val"
        if inner in HANDLE_TYPES or is_auto_handle_type(inner):
            cls = c_type_to_godot_class(base) + "Handle"
            lines.append(f"    if (_status != OCCTL_OK) {{ return Ref<{cls}>(); }}")
            lines.append(f"    if (!{local}) {{ return Ref<{cls}>(); }}")
            lines.append(f"    Ref<{cls}> _h;")
            lines.append(f"    _h.instantiate();")
            lines.append(
                f"    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>({local})));"
            )
            lines.append(f"    return _h;")
        elif inner in UINT64_ID_TYPES:
            lines.append(f"    if (_status != OCCTL_OK) {{ return 0; }}")
            lines.append(f"    return static_cast<int64_t>({local}->bits);")
        elif inner == "char":
            # Single const char** output → return String
            lines.append(f"    if (_status != OCCTL_OK) {{ return String(); }}")
            lines.append(f"    if (!{local}) {{ return String(); }}")
            lines.append(f"    return String({local});")
        else:
            # ----- HARDENED: Unknown ** type would silently drop data -----
            raise ValueError(
                f"[_generate_body] Unknown double-ptr out-param type "
                f"'{p.type_name.strip()}' (inner={inner!r}) in function {f.name}. "
                f"Cannot build return value."
            )
    elif handle_out_params and not _func_is_occtl_status(f):
        # Non-status C return with handle** out-param (unusual)
        lines.append(
            f"    return static_cast<int64_t>(reinterpret_cast<uintptr_t>(_{handle_out_params[0].name}_val));"
        )
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
    if t in ("double", "float"):
        return expr
    raise ValueError(
        f"Unknown C return type '{c_type}' in _c_to_godot_return. "
        f"Cannot convert expression '{expr}' to Godot type. "
        f"Either add to ENUM_TYPES, UINT64_ID_TYPES, VALUE_STRUCT_TYPES, or CPP_TO_GODOT_TYPE."
    )


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

    has_callbacks = any(_find_callback_userdata_pairs(f.params) for f in functions)
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
        "#include <godot_cpp/variant/callable.hpp>",
        "#include <cstdint>",
        f'#include "occtl/{parsed.header_include}"',
        "",
    ]
    for inc in sorted(set(value_type_includes)):
        lines.append(f'#include "{inc}"')
    lines.extend(
        [
            "",
            "using namespace godot;",
            "",
            f"class {cls} : public godot::RefCounted {{",
            f"    GDCLASS({cls}, godot::RefCounted)",
            "protected:",
            "    static void _bind_methods();",
            "public:",
        ]
    )
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
    lines.extend(
        [
            "};",
            "",
            f"#endif // {guard}",
            "",
        ]
    )
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


def _constant_godot_return_type(
    c: CConstant, consts: list[CConstant] | None = None
) -> str:
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
        p.type_name.strip() == "char*"
        or p.type_name.strip() in ("const char**", "const char * *")
        for f in functions
        for p in f.params
    ) or any(_is_two_call_buffer_func(f) for f in functions)

    lines = [
        f'#include "{cls}.h"',
        "",
        f'#include "occtl/{parsed.header_include}"',
        "",
    ]
    if has_vector:
        lines.append("#include <vector>")
        lines.append("")

    # Callback bridge functions
    needed_callbacks = _callback_types_needed(functions)
    if needed_callbacks:
        lines.append("namespace {")
        lines.append("struct _CallbackContext {")
        lines.append("    Callable callable;")
        lines.append("};")
        lines.append("")
        for cb_type in sorted(needed_callbacks):
            if cb_type in CALLBACK_BRIDGE_SOURCE:
                bridge_code = CALLBACK_BRIDGE_SOURCE[cb_type]
                for line in bridge_code.strip().split("\n"):
                    lines.append(line)
        lines.append("} // namespace")
        lines.append("")

    lines.append(f"void {cls}::_bind_methods() {{")
    for c in _filtered_constants(parsed.constants):
        ret = _constant_godot_return_type(c, parsed.constants)
        if ret == "int":
            lines.append(f"    BIND_CONSTANT({c.name});")
        else:
            lines.append(
                f'    godot::ClassDB::bind_method(godot::D_METHOD("const_{c.name}"), &{cls}::const_{c.name});'
            )
    for enum in parsed.enums:
        for ev in enum.values:
            lines.append(
                f'    godot::ClassDB::bind_integer_constant(get_class_static(), "{escape(enum.enum_name)}", "{ev.name}", {ev.name});'
            )
    method_names = _function_method_names(functions)
    for f in functions:
        mname = method_names[f.name]
        defvals = _method_defvals(f)
        lines.append(
            f'    godot::ClassDB::bind_method(godot::D_METHOD("{mname}"{_method_arg_names(f)}), &{cls}::{mname}{defvals});'
        )
    if not functions and not parsed.constants and not parsed.enums:
        lines.append(
            f'    godot::ClassDB::bind_method(godot::D_METHOD("_unused"), &{cls}::_unused);'
        )
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
        ast.Add: op.add,
        ast.Sub: op.sub,
        ast.Mult: op.mul,
        ast.Div: op.truediv,
        ast.USub: op.neg,
        ast.UAdd: op.pos,
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
        import ast
        import operator as op

        allowed_ops = {
            ast.Add: op.add,
            ast.Sub: op.sub,
            ast.Mult: op.mul,
            ast.FloorDiv: op.floordiv,
            ast.USub: op.neg,
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


def _c_type_to_doc_type_ref(c_type: str, rest: str = "") -> str:
    """Convert a C type to a Godot doc cross-reference link string.
    Returns e.g. '[OcctlPoint3]' or empty string if no good link."""
    t = c_type.strip()
    t_base = (
        re.sub(r"(?:^const\s+|\s*\*+$)", "", t).strip()
        if not c_type.startswith("const")
        else re.sub(r"^\s*const\s+", "", t).rstrip("* ").strip()
    )
    # Handle const pointers
    if t.startswith("const ") and t.endswith("*"):
        inner = t[len("const ") : -1].strip()
        if is_value_struct_type(inner):
            cls = c_type_to_godot_class(inner)
            return f"[{cls}]{rest}"
        if inner in UINT64_ID_TYPES:
            return f"[b]{_C_TYPE_DOC_DESC.get(inner, inner)}[/b]{rest}"
        return rest
    if is_value_struct_type(t):
        cls = c_type_to_godot_class(t)
        return f"[{cls}]{rest}"
    if t in HANDLE_TYPES:
        cls = c_type_to_godot_class(t) + "Handle"
        return f"[{cls}]{rest}"
    if t in UINT64_ID_TYPES:
        return f"[b]{_C_TYPE_DOC_DESC.get(t, t)}[/b]{rest}"
    if t in ENUM_TYPES:
        return f"[b]enum[/b]{rest}"
    return rest


def _c_type_to_godot_doc_type(c_type: str) -> str:
    """Map C type to Godot type string for doc (param type, return type)."""
    t = c_type.strip()
    gt = godot_param_type(t)
    if gt == "int" and t in ENUM_TYPES:
        return "int"
    return gt


def _describe_return(ret_mapped: str, c_ret: str) -> str:
    """Generate a human-readable [return] description."""
    if ret_mapped == "void":
        return ""
    if ret_mapped == "int" and c_ret.strip() == "occtl_status_t":
        return "    [return] Status code ([constant OcctlCore.OCCTL_OK] on success)."
    if ret_mapped.startswith("Ref<"):
        inner = ret_mapped[4:-1]
        if inner.endswith("Handle"):
            return f"    [return] A new [{inner}] handle, or null on failure."
        return f"    [return] A new [{inner}]."
    if ret_mapped == "PackedInt64Array":
        return "    [return] Array of node/UID values."
    if ret_mapped == "PackedFloat64Array":
        return "    [return] Array of double values."
    if ret_mapped == "PackedInt32Array":
        return "    [return] Array of int values."
    if ret_mapped == "String":
        return "    [return] String result."
    if ret_mapped == "bool":
        return "    [return] Boolean result."
    if ret_mapped == "int":
        return "    [return] Integer result."
    return f"    [return] {ret_mapped} result."


def _describe_param(p: CParameter, ret: str) -> str:
    """Generate a [param name] description line for a parameter."""
    t = p.type_name.strip()
    gt = godot_param_type(t)
    base_desc = ""
    if is_out_param(t, p.name, ret):
        base_desc = "Output parameter."
    elif t in ENUM_TYPES:
        base_desc = "Enum value."
    elif is_value_struct_type(t):
        cls = c_type_to_godot_class(t)
        base_desc = f"A [{cls}]."
    elif t in HANDLE_TYPES:
        cls = c_type_to_godot_class(t) + "Handle"
        base_desc = f"A [{cls}] handle."
    elif t.startswith("const ") and t.endswith("*"):
        inner = t[len("const ") : -1].strip()
        if is_value_struct_type(inner):
            cls = c_type_to_godot_class(inner)
            base_desc = f"An optional [{cls}]. Pass null to use defaults."
        elif inner in UINT64_ID_TYPES:
            base_desc = f"A {_C_TYPE_DOC_DESC.get(inner, inner)}."
        elif inner in HANDLE_TYPES:
            cls = c_type_to_godot_class(inner) + "Handle"
            base_desc = f"A [{cls}] handle."
        else:
            base_desc = "Input parameter."
    elif t in UINT64_ID_TYPES:
        base_desc = f"A {_C_TYPE_DOC_DESC.get(t, t)}."
    else:
        base_desc = "Input parameter."
    return f"    [param {p.name}] {base_desc}"


def generate_wrapper_doc_xml(parsed: ParsedHeader) -> str:
    cls = _wrapper_class_name(parsed.header_include)
    methods = []
    constants = []

    for c in parsed.constants:
        ret = _constant_godot_return_type(c, parsed.constants)
        if ret in ("int", "bool"):
            # Integer/bool constants go in <constants> section (class-level)
            constants.append(
                f'\t\t<constant name="{escape(c.name)}" value="{escape(str(c.value))}">'
            )
            desc = c.doc_comment or f"Constant for #define {c.name}"
            # Add cross-reference hint
            val_lower = str(c.value).lower()
            if val_lower in ("occtl_ok", "0") and "ok" in c.name.lower():
                desc += " Success status."
            elif val_lower == "occtl_buffer_too_small":
                desc += " Returned when a buffer is too small for the output."
            constants.append(f"\t\t\t{desc}.")
            constants.append("\t\t</constant>")
        else:
            # Float/double/string constants keep as <method> tags (no GDScript constant)
            methods.append(f'\t\t<method name="const_{escape(c.name)}">')
            methods.append(f'\t\t\t<return type="{ret}" />')
            methods.append("\t\t\t<description>")
            desc = c.doc_comment or f"Constant wrapper for #define {c.name}"
            if "pi" in c.name.lower():
                desc += " Mathematical constant pi."
            methods.append(f"\t\t\t\t{desc}.")
            methods.append("\t\t\t</description>")
            methods.append("\t\t</method>")

    for enum in parsed.enums:
        for ev in enum.values:
            # Enum values go in <constants> section (class-level)
            constants.append(
                f'\t\t<constant name="{escape(ev.name)}" value="{escape(str(ev.value))}">'
            )
            desc = f"Enum value = {ev.value}"
            enum_name_lower = enum.enum_name.lower()
            if "status" in enum_name_lower:
                desc += (
                    f" Status code. Defined in [enum {cls}.{escape(enum.enum_name)}]."
                )
            elif "kind" in enum_name_lower:
                desc += f" Kind identifier. Defined in [enum {cls}.{escape(enum.enum_name)}]."
            else:
                desc += f" Defined in [enum {cls}.{escape(enum.enum_name)}]."
            constants.append(f"\t\t\t{desc}")
            constants.append("\t\t</constant>")

    method_names = _function_method_names(parsed.functions)
    for f in parsed.functions:
        if _is_two_call_buffer_func(f):
            ret_mapped = _two_call_buffer_doc_return_type(f)
        else:
            ret_mapped = _func_return_type_mapped(f)
        mname = method_names[f.name]
        methods.append(f'\t\t<method name="{escape(mname)}">')
        if ret_mapped != "void":
            methods.append(f'\t\t\t<return type="{ret_mapped}" />')
        ret = f.return_type.strip()
        # Filter out string-length-pair size params and buffer triplet params
        kept_params = []
        for i, p in enumerate(f.params):
            if _is_stripped_out_param(p, ret) or _is_buffer_triplet_param(f, p):
                continue
            if _is_in_string_len_pair(f, i):
                # Keep the string param but skip the size param
                for str_idx, size_idx in _find_string_len_pairs(f):
                    if i == size_idx:
                        break  # skip size param
                else:
                    kept_params.append(p)
            else:
                kept_params.append(p)
        for i, p in enumerate(kept_params):
            gt = _c_type_to_godot_doc_type(p.type_name.strip())
            methods.append(
                f'\t\t\t<argument index="{i}" name="{escape(p.name)}" type="{gt}" />'
            )
        methods.append("\t\t\t<description>")
        doc = f.doc_comment or f"Generated binding for {f.name}."
        methods.append(f"\t\t\t\t{doc}")
        # Add [param] descriptions for each kept param
        for p in kept_params:
            param_desc = _describe_param(p, ret)
            methods.append(f"\t\t\t\t{param_desc}")
        # Add [return] description
        ret_desc = _describe_return(ret_mapped, ret)
        if ret_desc:
            methods.append(f"\t\t\t\t{ret_desc}")
        methods.append("\t\t</description>")
        methods.append("\t\t</method>")

    methods_xml = "\n".join(methods)
    constants_xml = "\n".join(constants)
    has_constants = bool(constants)
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
        + (f"\t<constants>\n{constants_xml}\n\t</constants>\n" if has_constants else "")
        + "</class>\n"
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
            lines.append('    if v == null: return "Failed: {c.name} returned null"')
        lines.append('    return ""')
        lines.append("")

    for enum in parsed.enums:
        for ev in enum.values:
            lines.append(f"static func test_{ev.name}() -> String:")
            lines.append(f"    var v = {cls}.{ev.name}")
            lines.append('    if v < 0: return "Failed: enum value negative"')
            lines.append('    return ""')
            lines.append("")

    # Tests for functions with string+length pair auto-collapse
    method_names = _function_method_names(parsed.functions)
    for f in parsed.functions:
        pairs = _find_string_len_pairs(f)
        if not pairs:
            continue
        mname = method_names[f.name]
        lines.append(f"static func test_{mname}_string_pair() -> String:")
        # Build arg list: use empty string for string params, defaults for others
        ret = f.return_type.strip()
        string_len_indices = _get_string_len_indices(pairs)
        kept = _build_kept_params(f, ret, pairs, string_len_indices)
        args = []
        for p in kept:
            t = p.type_name.strip()
            if _is_in_string_len_pair(f, f.params.index(p)):
                args.append('"test"')
            elif t == "bool":
                args.append("false")
            elif t in ("double", "float"):
                args.append("0.0")
            elif t.endswith("*") and not t.endswith("**"):
                # Pointer types (handles, out-params, buffers) become Ref<T>
                # or arrays in GDScript, where null is a valid default.
                args.append("null")
            else:
                # Non-pointer: check if this is a value struct/handle type (Ref<T>)
                base = re.sub(r"\s+(const|volatile)\s*$", "", t)
                base = re.sub(r"^(const|volatile)\s+", "", base).strip()
                typed = _resolve_typedef(base)
                if (
                    typed in HANDLE_TYPES
                    or is_auto_handle_type(typed)
                    or is_value_struct_type(typed)
                ):
                    args.append("null")
                else:
                    # Non-pointer primitive (int, occtl_node_id_t, enum, etc.)
                    args.append("0")
        # Create a local instance since test methods are static (cannot access _w)
        lines.append(f"    var _w = {cls}.new()")
        lines.append(f"    _w.{mname}({', '.join(args)})")
        lines.append('    return ""')
        lines.append("")

    return "\n".join(lines)
