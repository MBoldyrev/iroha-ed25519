if(NOT UNIX)
  return()
endif()

add_library(dev_random INTERFACE)
target_sources(dev_random
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/random.c
  )

ed25519_add_library(dev_random RANDOM)
