cmake_minimum_required (VERSION 3.0)

project (mulle-utf C)

set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/mulle-configuration/cmake)
message(STATUS "CMAKE_MODULE_PATH is ${CMAKE_MODULE_PATH}")
message(STATUS "CMAKE_BUILD_TYPE is ${CMAKE_BUILD_TYPE}")
if( "${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
  include( Debug)
else()
  include( Release)
endif()


set( HEADERS
src/mulle_utf.h
src/mulle_utf16.h
src/mulle_utf32.h
src/mulle_utf16_string.h
src/mulle_utf32_string.h
src/mulle_utf8.h
src/mulle_char5.h
src/mulle_char7.h
src/mulle_utf_convenience.h
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
src/mulle_utf_is_validurlscheme.h
src/mulle_utf_is_validurluser.h
src/mulle_utf_is_whitespace.h
src/mulle_utf_is_whitespaceornewline.h
src/mulle_utf_tolower.h
src/mulle_utf_toupper.h
)


add_library( mulle_utf
src/mulle_char5.c
src/mulle_char7.c
src/mulle_utf8.c
src/mulle_utf16.c
src/mulle_utf32.c
src/mulle_utf16_string.c
src/mulle_utf32_string.c
src/mulle_utf_convenience.c
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
src/mulle_utf_is_validurlscheme.c
src/mulle_utf_is_validurluser.c
src/mulle_utf_is_whitespace.c
src/mulle_utf_is_whitespaceornewline.c
src/mulle_utf_tolower.c
src/mulle_utf_toupper.c
)


find_library( MULLE_ALLOCATOR_LIBRARY NAMES mulle_allocator)
message( STATUS "MULLE_ALLOCATOR_LIBRARY is ${MULLE_ALLOCATOR_LIBRARY}")
find_library( MULLE_TEST_ALLOCATOR_LIBRARY NAMES mulle_test_allocator)
message( STATUS "MULLE_TEST_ALLOCATOR_LIBRARY is ${MULLE_TEST_ALLOCATOR_LIBRARY}")


set( TARGET_ALL_LOAD_LIBRARIES
$<TARGET_FILE:mulle_utf>
${MULLE_ALLOCATOR_LIBRARY}
${MULLE_TEST_ALLOCATOR_LIBRARY}
)

foreach( library ${TARGET_ALL_LOAD_LIBRARIES})
   list( APPEND TARGET_FORCE_ALL_LOAD_LIBRARIES "${FORCE_LOAD_PREFIX}${library}")
endforeach( library)


if( MSVC)
   set( DEF_FILE mulle_utf_standalone.def)
   set_source_files_properties( ${DEF_FILE} PROPERTIES HEADER_FILE_ONLY TRUE)
   set( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS OFF)
   set( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /DEF:${DEF_FILE}")
   # /NODEFAULTLIB:MSVCRT")

   message( STATUS "MSVC will generate \"${DEF_FILE}\" from ${TARGET_ALL_LOAD_LIBRARIES}")

   add_definitions( -DMULLE_ALLOCATOR_EXTERN_GLOBAL=extern)

   add_custom_command( OUTPUT ${DEF_FILE}
                       COMMAND mulle-mingw-dumpdef.bat -o "${DEF_FILE}"
                               --directory "${BUILD_RELATIVE_DEPENDENCIES_DIR}/lib"
                               --prefix "mulle" 
                               --prefix "Mulle" 
                               --prefix "ns"
                               --prefix "NS" 
                               --prefix "_mulle" 
                               --prefix "_Mulle" 
                               --prefix "_ns"
                               --prefix "_NS" 
                               ${TARGET_ALL_LOAD_LIBRARIES}
                       DEPENDS "${SOURCES}" "${HEADERS}"
                       VERBATIM)
   find_program( CREATE_INC mulle-objc-create-dependencies-inc.bat ${DEPENDENCIES_DIR}/bin)
endif()

add_library( mulle_utf_standalone SHARED
src/mulle_utf_standalone.c
${DEF_FILE}
)

add_dependencies( mulle_utf_standalone mulle_utf)

TARGET_LINK_LIBRARIES( mulle_utf_standalone
${BEGIN_ALL_LOAD}
${TARGET_FORCE_ALL_LOAD_LIBRARIES}
${END_ALL_LOAD}
${DEPENDENCIES}
)


INSTALL(TARGETS mulle_utf mulle_utf_standalone DESTINATION "lib")
INSTALL(FILES ${HEADERS} DESTINATION "include/mulle_utf")
