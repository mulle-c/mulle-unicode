cmake_minimum_required( VERSION 3.0)

project( mulle-utf C)

set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/mulle-configuration/cmake)
message( STATUS "CMAKE_MODULE_PATH is ${CMAKE_MODULE_PATH}")
message( STATUS "CMAKE_BUILD_TYPE is ${CMAKE_BUILD_TYPE}")
if( "${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
  include( Debug)
else()
  include( Release)
endif()

set( MULLE_UTF_LIBRARY ON)
include( CMakeSourcesAndHeaders.txt)
include( CMakeDependencies.txt)


set( PUBLIC_HEADERS
${HEADERS}
CMakeDependencies.txt
)


add_library( mulle_utf
${SOURCES}
)

set( STANDALONE_BASE_NAME "mulle_utf")
set( STANDALONE_NAME "mulle_utf_standalone")
set( STANDALONE_DEFINITIONS ${MULLE_UTF_DEFINITIONS})
set( STANDALONE_ALL_LOAD_LIBRARIES
$<TARGET_FILE:mulle_utf>
${C_DEPENDENCY_LIBRARIES}
)

include( Standalone)

INSTALL( TARGETS mulle_utf mulle_utf_standalone DESTINATION "lib")
INSTALL( FILES ${PUBLIC_HEADERS} DESTINATION "include/mulle_utf")

include( MulleTest)
