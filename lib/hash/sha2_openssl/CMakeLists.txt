find_package(OpenSSL QUIET)
if(NOT OPENSSL_FOUND)
  return()
endif()

add_library(sha2_openssl INTERFACE)
target_sources(sha2_openssl
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/sha256.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sha512.c
  )
target_link_libraries(sha2_openssl INTERFACE ${OPENSSL_CRYPTO_LIBRARY})
target_include_directories(sha2_openssl INTERFACE ${OPENSSL_INCLUDE_DIR})
ed25519_hash_type_set(sha2_openssl sha2)

ed25519_add_library(sha2_openssl HASH)
