cmake_minimum_required (VERSION 3.0)

project (mulle-utf)

set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/mulle-configuration)
message(STATUS "CMAKE_MODULE_PATH is ${CMAKE_MODULE_PATH}")
message(STATUS "CMAKE_BUILD_TYPE is ${CMAKE_BUILD_TYPE}")
if( "${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
  include( Debug)
else()
  include( Release)
endif()


set(HEADERS
src/mulle_utf.h
src/mulle_utf16.h
src/mulle_utf32.h
src/mulle_utf8.h
src/mulle_utf_type.h
)


add_library(mulle_utf
src/mulle_utf16.c
src/mulle_utf32.c
src/mulle_utf8.c
)


INSTALL(TARGETS mulle_utf DESTINATION "lib")
INSTALL(FILES ${HEADERS} DESTINATION "include/mulle_utf")

