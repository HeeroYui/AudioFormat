cmake_minimum_required(VERSION 2.8.3)
project(audio)

set(CMAKE_VERBOSE_MAKEFILE ON)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  etk
  audio_msg
  )


###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  INCLUDE_DIRS ../
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS etk
  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  ..
  ${catkin_INCLUDE_DIRS}
)

## Declare a cpp library
add_library(${PROJECT_NAME}
  ../${PROJECT_NAME}/debug.cpp
  ../${PROJECT_NAME}/channel.cpp
  ../${PROJECT_NAME}/format.cpp
  ../${PROJECT_NAME}/Time.cpp
  ../${PROJECT_NAME}/Duration.cpp
  ../${PROJECT_NAME}/int8_8_t.cpp
  ../${PROJECT_NAME}/int8_16_t.cpp
  ../${PROJECT_NAME}/int16_16_t.cpp
  ../${PROJECT_NAME}/int16_32_t.cpp
  ../${PROJECT_NAME}/int24_24_t.cpp
  ../${PROJECT_NAME}/int24_32_t.cpp
  ../${PROJECT_NAME}/int32_32_t.cpp
  ../${PROJECT_NAME}/int32_64_t.cpp
  ../${PROJECT_NAME}/int64_64_t.cpp
  ../${PROJECT_NAME}/float_t.cpp
  ../${PROJECT_NAME}/double_t.cpp
)


## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
#add_dependencies(${PROJECT_NAME} test_perfo_core_generate_messages_cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
)

#############
## Install ##
#############

## Mark executables and/or libraries for installation
install(TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)

## Mark cpp header files for installation
install(DIRECTORY ../${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
)
