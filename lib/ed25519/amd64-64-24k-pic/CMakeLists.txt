if (NOT CAN_BUILD_AMD64)
  return()
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

FILE(GLOB internal_sources ${CMAKE_CURRENT_SOURCE_DIR}/*.[cs])
set(maybe_export_sources ${CMAKE_CURRENT_SOURCE_DIR}/ed25519.c)

list(REMOVE_ITEM internal_sources ${maybe_export_sources})

add_library(amd64-64-24k-pic OBJECT)
target_sources(amd64-64-24k-pic
  INTERFACE
    ${maybe_export_sources}
  PRIVATE
    ${internal_sources}
  )
ed25519_add_library(amd64-64-24k-pic EDIMPL)
