cmake_minimum_required (VERSION 2.6)
project (principle_graph)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()


### The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)


### set complie flags
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")


### setup include directories
include_directories("src/")
# external include goes here
include_directories("../DiMorSC_BIGGER/DiMorSC/extern/boost/")


### compile libraries
add_library(MYLIB src/pointset.cpp)


### Output
add_executable(PrincipleGraph src/PrincipleGraph.cpp)
add_executable(testPointset tests/testPointset.cpp)

target_link_libraries (PrincipleGraph MYLIB)
target_link_libraries (testPointset MYLIB)