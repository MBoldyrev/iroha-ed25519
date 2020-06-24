function(ed25519_add_library LIBNAME TYPE)
  # store current library in SUPPORTED libraries set, if it is supported
  if(NOT LIBNAME IN_LIST ED25519_SUPPORTED_LIBRARIES_${TYPE})
    set(ED25519_SUPPORTED_LIBRARIES_${TYPE}
      ${ED25519_SUPPORTED_LIBRARIES_${TYPE}} ${LIBNAME}
      CACHE INTERNAL "" FORCE)
  endif()

  get_property(lib_type TARGET ${LIBNAME} PROPERTY TYPE)
  if(src_lib_type STREQUAL "OBJECT_LIBRARY")
    set_target_properties(${LIBNAME} PROPERTIES
      EXCLUDE_FROM_ALL          ON
      RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/bin
      ARCHIVE_OUTPUT_PATH       ${CMAKE_BINARY_DIR}/archive_output_directory
      LIBRARY_OUTPUT_PATH       ${CMAKE_BINARY_DIR}/library_output_directory
      )
  endif()

endfunction(ed25519_add_library)
