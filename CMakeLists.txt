cmake_minimum_required(VERSION 2.8)

project(AnalyticalMisfitInterfaces)

#Check if important libraries are available.

#Gnu Scientific library
set(CMAKE_MODULE_PATH 
    ${CMAKE_MODULE_PATH} 
    "${CMAKE_SOURCE_DIR}/CMakeModules") # findGSL module is not shipped with cmake
find_package(GSL REQUIRED)

#BLAS
find_package(BLAS REQUIRED)

#tests
add_subdirectory (tests)
enable_testing ()
add_test (NAME MyTest COMMAND Test)

#library
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
file(GLOB CPP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_library (interface ${CPP_SOURCES})
