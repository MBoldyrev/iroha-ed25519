foreach (_hash ${ED25519_SUPPORTED_LIBRARIES_HASH})
  set(_target test-${_hash})
  ed25519_add_test(${_target}
    sha_test.cpp
    )
  ed25519_target_link_libraries(${_target}
    ${_hash}
    )

  if (TARGET ${_hash})
    ed25519_hash_type_get(_type "${_hash}")
    target_compile_options(${_target} PUBLIC
      -DTESTDATA_PATH=${CMAKE_CURRENT_SOURCE_DIR}/${_type}.input.txt
      )
  else()
    continue()
  endif ()
endforeach ()
