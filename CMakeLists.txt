cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(CPlusPlusCmakeTemplate CXX)
include(CTest)
include(ExternalProject)

#######################
# Project Setup
#######################

# Turn on C++ 11 support
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set paths
#set(CMAKE_MACOSX_RPATH 1)
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#######################
# Compiler Setup
#######################

# All Warnings # -Werror -pedantic
set(WARNING_FLAGS "-Wall -Wextra ")
set(SHARED_FLAGS "${WARNING_FLAGS} ${SECURITY_FLAGS}")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang")
    message(STATUS "Using Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SHARED_FLAGS} -std=c++11 -stdlib=libc++")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -ldl")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    message(STATUS "Using GCC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SHARED_FLAGS} -std=c++11 -pthread -ldl")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread -ldl")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    message(STATUS "Using MSVC")
    add_definitions(
        /Wall
        /D "_CRT_SECURE_NO_WARNINGS"
    )
    # Enable multi-process compilation.
    if (NOT MSVC60 AND NOT MSVC70 AND NOT MSVC71)
        List(APPEND CFLAGS /MP)
    endif()
endif()

#######################
# Project Dependencies
#######################

# Make sure Boost is installed
#find_package(Boost COMPONENTS system filesystem REQUIRED)
#if(Boost_FOUND)
#    include_directories(${Boost_INCLUDE_DIR})
#    add_definitions("-DHAS_BOOST")
#endif()

#######################
# Test Dependencies
#######################

# Testing
add_subdirectory(lib/gtest-1.7.0)
enable_testing()
include_directories(lib/gtest-1.7.0/include)

#add_subdirectory(lib/gmock-1.7.0)
#include_directories(lib/gmock-1.7.0/include)

#######################
# Project Sources
#######################

# Local header files are placed in the include directory.
include_directories(include)

# Sample Module
add_subdirectory(src)



