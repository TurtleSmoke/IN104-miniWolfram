#Project setup
cmake_minimum_required(VERSION 3.0)
project(miniWolfram
        VERSION 1.0
        DESCRIPTION "A simple program to simlulate calculator"
        LANGUAGES C)

#Set up the compiler flags
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Wextra -Wpedantic -g")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

#Setup source, headers, and object files
include_directories(src)
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.c)
list(REMOVE_ITEM SOURCES ${PROJECT_SOURCE_DIR}/src/miniWolfram.c)
# Note: headers are not mandatory, but it is useful with some IDEs for code completion
file(GLOB HEADERS ${PROJECT_SOURCE_DIR}/src/*.h)

# Compile source files into a library
add_library(miniWolframLib ${SOURCES} ${HEADERS})

# Create executable and link with library
add_executable(miniWolfram src/miniWolfram.c)
target_link_libraries(miniWolfram miniWolframLib)

#  ================  GTest  ================
# Project setup
project(miniWolframTest
        VERSION 1.0
        DESCRIPTION "GTest for miniWolfram"
        LANGUAGES CXX)
# Set up the C++ compiler flags
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -g")

# Gtest is a git submodule, and it is cmake compatible
add_subdirectory(third_party/googletest)
enable_testing()

# Setup test source files
file(GLOB TEST_SOURCES ${PROJECT_SOURCE_DIR}/test/*.cc)

message(STATUS "TEST_SOURCES: ${TEST_SOURCES}")

# Create executable and link with library
add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests gtest gtest_main)
target_link_libraries(tests miniWolframLib)
target_compile_options(tests PRIVATE -O0 -g3)
target_link_options(tests PRIVATE -O0 -g3)
add_test(NAME tests COMMAND ./tests)