include_directories(${CMAKE_CURRENT_SOURCE_DIR})

FILE(GLOB internal_sources ${CMAKE_CURRENT_SOURCE_DIR}/*.c)
set(maybe_export_sources ${CMAKE_CURRENT_SOURCE_DIR}/ed25519.c)

list(REMOVE_ITEM internal_sources ${maybe_export_sources})

# pure C implementation, will work on all platforms
add_library(ref10 OBJECT)
target_sources(ref10
  INTERFACE
    ${maybe_export_sources}
  PRIVATE
    ${internal_sources}
  )
ed25519_add_library(ref10 EDIMPL)
