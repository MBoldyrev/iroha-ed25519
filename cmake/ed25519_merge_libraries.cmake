function(ed25519_merge_libraries TARGET LIBTYPE)
  set(options "")
  set(oneValueArgs "VERSION")
  set(multiValueArgs LIBRARIES COMPILE_OPTIONS)
  cmake_parse_arguments(ARG
    "${options}"
    "${oneValueArgs}"
    "${multiValueArgs}"
    ${ARGN}
    )

  # create dummy C source file
  set(${TARGET}_SRC ${CMAKE_BINARY_DIR}/dummy/${TARGET}_dummy.c)
  configure_file_content("const char* libed25519_version = \"${ARG_VERSION}\";" ${${TARGET}_SRC})

  # define target
  add_library(${TARGET} ${LIBTYPE}
    ${${TARGET}_SRC}
    )

  ed25519_target_link_libraries(${TARGET}
    ${ARG_LIBRARIES}
    )
  target_compile_definitions(${TARGET} PRIVATE
    ${ARG_COMPILE_OPTIONS}
    )
  target_include_directories(${TARGET}
    PRIVATE
      ${CMAKE_CURRENT_BINARY_DIR}
    INTERFACE
      $<INSTALL_INTERFACE:include>
    )

  foreach (lib ${ARG_LIBRARIES})
    if (TARGET ${lib})
      add_dependencies(${TARGET} ${lib})
    endif ()
  endforeach ()

  set_target_properties(${TARGET} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
    )
endfunction()
