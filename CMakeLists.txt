cmake_minimum_required(VERSION 2.8)

project(AnalyticalMisfitInterfaces)

#tests
add_subdirectory (tests)

#Check if important libraries are available.

#Gnu Scientific library
set(CMAKE_MODULE_PATH 
    ${CMAKE_MODULE_PATH} 
    "${CMAKE_SOURCE_DIR}/CMakeModules") # findGSL module is not shipped with cmake
find_package(GSL REQUIRED)

#BLAS
find_package(BLAS REQUIRED)

#BOOST test library
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
file(GLOB CPP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
set(EXEC_NAME AnalyticalMisfitInterfaces_test)
add_executable(${EXEC_NAME} ${CPP_SOURCES})

target_link_libraries(${EXEC_NAME} 
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                      ${GSL_LIBRARIES}
                      ${BLAS_LIBRARIES})
