cmake_minimum_required(VERSION 3.1...3.15)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

### Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib/chip/libchip.so")

project(chip VERSION 1.0
        	DESCRIPTION "chip game engine"
		LANGUAGES CXX)

add_subdirectory(src/core)

# add the engine library
add_library(chip SHARED src/main.cc include/main.h)

target_link_libraries(chip PUBLIC core)

target_include_directories(chip PUBLIC
                          ${CMAKE_SOURCE_DIR}/include/
                          )

install(TARGETS chip DESTINATION lib/chip)
install(FILES include/main.h DESTINATION include/chip)