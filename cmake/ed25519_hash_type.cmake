function(ed25519_hash_type_set LIB HASH_TYPE)
  set_property(GLOBAL PROPERTY ED25519_HASH_TYPE_${LIB} ${HASH_TYPE})
endfunction()

macro(ed25519_hash_type_get HASH_TYPE_VAR LIB)
  get_property(${HASH_TYPE_VAR} GLOBAL PROPERTY ED25519_HASH_TYPE_${LIB})
endmacro()
