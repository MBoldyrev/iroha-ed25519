if(NOT (WIN32 OR MSVC OR MSYS OR MINGW))
  return()
endif()

find_library(BCRYPT_LIB bcrypt)
if(NOT BCRYPT_LIB)
  return()
endif()

message(STATUS "Found bcrypt library: ${BCRYPT_LIB}")

add_library(bcryptgen OBJECT)
target_sources(bcryptgen
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/randombytes.c
  )
target_link_libraries(bcryptgen ${BCRYPT_LIB})

ed25519_add_library(bcryptgen RANDOM)
