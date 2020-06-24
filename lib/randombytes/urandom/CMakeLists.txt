if(NOT UNIX)
  return()
endif()

add_library(dev_urandom INTERFACE)
target_sources(dev_urandom
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/urandom.c
  )

ed25519_add_library(dev_urandom RANDOM)
