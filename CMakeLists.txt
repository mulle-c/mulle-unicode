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
src/mulle_char5.h
src/mulle_utf_type.h
src/mulle_utf_ctype.h
src/mulle_utf_is_noncharacter.h
src/mulle_utf_is_privatecharacter.h
src/mulle_utf_is_alphanumeric.h
src/mulle_utf_is_capitalized.h
src/mulle_utf_is_control.h
src/mulle_utf_is_decimaldigit.h
src/mulle_utf_is_decomposable.h
src/mulle_utf_is_letter.h
src/mulle_utf_is_lowercase.h
src/mulle_utf_is_newline.h
src/mulle_utf_is_nonbase.h
src/mulle_utf_is_nonpercentescape.h
src/mulle_utf_is_punctuation.h
src/mulle_utf_is_symbol.h
src/mulle_utf_is_uppercase.h
src/mulle_utf_is_validurlfragment.h
src/mulle_utf_is_validurlhost.h
src/mulle_utf_is_validurlpassword.h
src/mulle_utf_is_validurlpath.h
src/mulle_utf_is_validurlquery.h
src/mulle_utf_is_validurluser.h
src/mulle_utf_is_whitespace.h
src/mulle_utf_is_whitespaceornewline.h
src/mulle_utf_tolower.h
src/mulle_utf_toupper.h
)


add_library(mulle_utf
src/mulle_utf16.c
src/mulle_utf32.c
src/mulle_utf8.c
src/mulle_char5.c
src/mulle_utf_is_noncharacter.c
src/mulle_utf_is_privatecharacter.c
src/mulle_utf_is_alphanumeric.c
src/mulle_utf_is_capitalized.c
src/mulle_utf_is_control.c
src/mulle_utf_is_decimaldigit.c
src/mulle_utf_is_decomposable.c
src/mulle_utf_is_letter.c
src/mulle_utf_is_lowercase.c
src/mulle_utf_is_newline.c
src/mulle_utf_is_nonbase.c
src/mulle_utf_is_nonpercentescape.c
src/mulle_utf_is_punctuation.c
src/mulle_utf_is_symbol.c
src/mulle_utf_is_uppercase.c
src/mulle_utf_is_validurlfragment.c
src/mulle_utf_is_validurlhost.c
src/mulle_utf_is_validurlpassword.c
src/mulle_utf_is_validurlpath.c
src/mulle_utf_is_validurlquery.c
src/mulle_utf_is_validurluser.c
src/mulle_utf_is_whitespace.c
src/mulle_utf_is_whitespaceornewline.c
src/mulle_utf_tolower.c
src/mulle_utf_toupper.c
)


INSTALL(TARGETS mulle_utf DESTINATION "lib")
INSTALL(FILES ${HEADERS} DESTINATION "include/mulle_utf")

