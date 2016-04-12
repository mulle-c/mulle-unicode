cmake_minimum_required (VERSION 3.0)

project (mulle-utf)

#
# dont forget to wipe all cmake produced files before
# changing this
#

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
   set (CMAKE_C_FLAGS "-Wno-parantheses")
endif()

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g -DDEBUG -DMULLE_ATOMIC_TRACE")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -g -DNDEBUG")

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

