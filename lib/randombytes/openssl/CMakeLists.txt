find_package(OpenSSL QUIET)
if(NOT OPENSSL_FOUND)
  return()
endif()

add_library(rand_openssl INTERFACE)
target_sources(rand_openssl
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/randombytes.c
  )
target_link_libraries(rand_openssl INTERFACE ${OPENSSL_CRYPTO_LIBRARY})
target_include_directories(rand_openssl INTERFACE ${OPENSSL_INCLUDE_DIR})

if(BUILD STREQUAL "SHARED")
  target_link_libraries(rand_openssl INTERFACE dl)
endif()

ed25519_add_library(rand_openssl RANDOM)
