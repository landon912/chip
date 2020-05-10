set(HEADER_LIST 
    "${chip_SOURCE_DIR}/include/core/core.h"
)

set(SOURCE_LIST
    "${chip_SOURCE_DIR}/src/core/core.cc"
)

SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib/chip/libcore.so")

add_library(
        core
        SHARED
        ${SOURCE_LIST}
        ${HEADER_LIST}
)

target_include_directories(core PUBLIC ${CMAKE_SOURCE_DIR}/include/core/)

source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})

install(TARGETS core DESTINATION lib/chip)
install(FILES "${HEADER_LIST}" DESTINATION include/chip)