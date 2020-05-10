cmake_minimum_required(VERSION 3.1...3.15)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

### Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

project(sandbox VERSION 1.0
        	DESCRIPTION "sandbox"
		LANGUAGES CXX)

# add the engine library
add_executable(sandbox src/main.cc)

find_library(CHIP_LIB chip HINTS "/usr/local/lib/chip")
find_library(CORE_LIB core HINTS "/usr/local/lib/chip")

target_link_libraries(sandbox PUBLIC "${CHIP_LIB}")
target_link_libraries(sandbox PUBLIC "${CORE_LIB}")