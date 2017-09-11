cmake_minimum_required( VERSION 3.0)

project( mulle-utf C)

set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/mulle-configuration/cmake)
message(STATUS "CMAKE_MODULE_PATH is ${CMAKE_MODULE_PATH}")
message(STATUS "CMAKE_BUILD_TYPE is ${CMAKE_BUILD_TYPE}")
if( "${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
  include( Debug)
else()
  include( Release)
endif()

include( CMakeSourcesAndHeaders.txt)

find_library( MULLE_ALLOCATOR_LIBRARY NAMES mulle_allocator)
message( STATUS "MULLE_ALLOCATOR_LIBRARY is ${MULLE_ALLOCATOR_LIBRARY}")
find_library( MULLE_TEST_ALLOCATOR_LIBRARY NAMES mulle_test_allocator)
message( STATUS "MULLE_TEST_ALLOCATOR_LIBRARY is ${MULLE_TEST_ALLOCATOR_LIBRARY}")

set( DEPENDENCY_LIBRARIES
${MULLE_ALLOCATOR_LIBRARY}
${MULLE_TEST_ALLOCATOR_LIBRARY}
)


add_library( mulle_utf
${SOURCES}
)

set( STANDALONE_BASE_NAME "mulle_utf")
set( STANDALONE_NAME "mulle_utf_standalone")

set( TARGET_ALL_LOAD_LIBRARIES
$<TARGET_FILE:mulle_utf>
${DEPENDENCY_LIBRARIES}
)

include( Standalone)


INSTALL( TARGETS mulle_utf mulle_utf_standalone DESTINATION "lib")
INSTALL( FILES ${HEADERS} DESTINATION "include/mulle_utf")
