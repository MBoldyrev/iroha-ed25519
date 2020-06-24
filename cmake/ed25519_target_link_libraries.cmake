function(_link_ed25519_dependencies _target)
  if(NOT TARGET ${_target})
    message(FATAL_ERROR "${_target} is not target")
  endif()

  foreach(_lib IN ITEMS ${ARGN})
    # _lib may have property ED25519_LINK.
    # If it has this property, read property and link it to ${_target}
    get_target_property(_link "${_lib}" ED25519_LINK)
    if(_link)
      ed25519_target_link_libraries(${_target}
        ${_link}
        )
    endif()
  endforeach()

endfunction(_link_ed25519_dependencies _target)



function(ed25519_target_link_libraries _target)
  if(NOT TARGET ${_target})
    message(FATAL_ERROR "${_target} is not target")
  endif()

  get_target_property(_type ${_target} TYPE)
  if(_type STREQUAL "OBJECT_LIBRARY")
    if(ARGN) # target_link_libraries may be empty, in this case ARGN will be empty
      set_target_properties(${_target} PROPERTIES
        ED25519_LINK "${ARGN}"
        )
    endif()
  else()

    # target is not object library
    foreach(_lib IN ITEMS ${ARGN})
      if(NOT TARGET ${_lib})
        # flag
        target_link_libraries(${_target} PRIVATE ${_lib})
      else()

        get_target_property(_type "${_lib}" TYPE)

        if (   _type STREQUAL "OBJECT_LIBRARY"
            OR _type STREQUAL "INTERFACE_LIBRARY")
          get_property(src_lib_iface_sources TARGET ${_lib} PROPERTY INTERFACE_SOURCES)
          target_sources(${_target} PRIVATE ${src_lib_iface_sources})

          get_property(src_lib_iface_include_dirs TARGET ${_lib} PROPERTY INTERFACE_INCLUDE_DIRECTORIES)
          target_include_directories(${_target} PRIVATE ${src_lib_iface_include_dirs})

          get_property(src_lib_iface_link_libs TARGET ${_lib} PROPERTY INTERFACE_LINK_LIBRARIES)
          target_link_libraries(${_target} PRIVATE ${src_lib_iface_link_libs})
        endif()

        if (_type STREQUAL "OBJECT_LIBRARY")
          target_sources(${_target} PRIVATE $<TARGET_OBJECTS:${_lib}>)

          get_property(src_lib_link_libs TARGET ${_lib} PROPERTY LINK_LIBRARIES)
          target_link_libraries(${_target} PRIVATE ${src_lib_link_libs})

          get_property(src_lib_include_dirs TARGET ${_lib} PROPERTY INCLUDE_DIRECTORIES)
          target_include_directories(${_target} PRIVATE ${src_lib_include_dirs})

          # if _lib is object library, then add it to sources
          target_sources(${_target} PRIVATE
            $<TARGET_OBJECTS:${_lib}>
            )
        elseif(_type STREQUAL "SHARED_LIBRARY" OR _type STREQUAL "STATIC_LIBRARY")
          _link_ed25519_dependencies(${_target}
            ${_lib}
            )
          target_link_libraries(${_target} PRIVATE
            ${_lib}
            )
        endif()
      endif()
    endforeach()
  endif()
endfunction(ed25519_target_link_libraries)
