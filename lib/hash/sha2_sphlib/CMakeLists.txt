add_library(sha2_sphlib OBJECT)
target_sources(sha2_sphlib
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/sha2_256.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sha2_512.c
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/sha2.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sha2_big.c
  )
ed25519_hash_type_set(sha2_sphlib sha2)

ed25519_add_library(sha2_sphlib HASH)
