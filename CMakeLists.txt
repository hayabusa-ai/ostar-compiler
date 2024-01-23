cmake_minimum_required(VERSION 3.18)
project(ostar C CXX)

include(cmake/utils.cmake)
include(cmake/contrib.cmake)

if(EXISTS ${CMAKE_BINARY_DIR}/config.cmake)
  include(${CMAKE_BINARY_DIR}/config.cmake)
else()
  if(EXISTS ${CMAKE_SOURCE_DIR}/config.cmake)
    include(${CMAKE_SOURCE_DIR}/config.cmake)
  endif()
endif()

ostar_option(USE_CUDA "Build with CUDA" ON)