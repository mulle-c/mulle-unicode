cmake_minimum_required( VERSION 3.0)

project( mulle-utf C)


### mulle-sde environment

# add cmake module paths to search path
list( INSERT CMAKE_MODULE_PATH 0 "${PROJECT_SOURCE_DIR}/cmake/share")
list( INSERT CMAKE_MODULE_PATH 0 "${PROJECT_SOURCE_DIR}/cmake")

include( Environment)


### Files

include( PreFiles OPTIONAL)

set( MULLE_UTF_LIBRARY ON)

#
# Include all non underscored .cmake files in ./cmake
#
file( GLOB LOCAL_CMAKE_INCLUDES
   "cmake/[A-Za-z0-9]*.cmake"
)

foreach( FILE ${LOCAL_CMAKE_INCLUDES} )
   include( "${FILE}")
endforeach()


include_directories( ${INCLUDE_DIRS})

include( PostFiles OPTIONAL)

### Library

include( PreLibrary OPTIONAL)

add_library( "mulle-utf"
${SOURCES}
${PUBLIC_HEADERS}
${PRIVATE_HEADERS}
${CMAKE_EDITABLE_FILES}
)

if( BUILD_SHARED_LIBS)
   target_link_libraries( mulle-utf
${DEPENDENCY_LIBRARIES}
${OS_SPECIFIC_LIBRARIES}
)
endif()

include( PostLibrary OPTIONAL)


set( STANDALONE_BASE_NAME "mulle-utf")
set( STANDALONE_NAME "mulle-utf-standalone")
set( STANDALONE_DEFINITIONS ${MULLE_UTF_DEFINITIONS})
set( STANDALONE_DEPENDENCIES
mulle-utf
)

set( STANDALONE_ALL_LOAD_LIBRARIES
$<TARGET_FILE:mulle-utf>
${DEPENDENCY_LIBRARIES}
${OPTIONAL_DEPENDENCY_LIBRARIES}
)

set( STANDALONE_NORMAL_LOAD_LIBRARIES
${OS_SPECIFIC_LIBRARIES}
)
include( Standalone)

### Install

include( PreInstall OPTIONAL)

install( TARGETS "mulle-utf" "mulle-utf-standalone" DESTINATION "lib")
install( FILES ${PUBLIC_HEADERS}  DESTINATION "include/mulle-utf")
install( FILES ${PRIVATE_HEADERS} DESTINATION "include/mulle-utf/private")

install( FILES ${CMAKE_INCLUDES}  DESTINATION "include/mulle-utf/cmake")

include( PostInstall OPTIONAL)
