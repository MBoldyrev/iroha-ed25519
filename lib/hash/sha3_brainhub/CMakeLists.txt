add_library(sha3_brainhub OBJECT)
target_sources(sha3_brainhub
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/sha3_256.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sha3_512.c
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/sha3.c
  )
ed25519_hash_type_set(sha3_brainhub sha3)

ed25519_add_library(sha3_brainhub HASH)
