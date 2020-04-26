set(HEADER_LIST "${chip_SOURCE_DIR}/include/core/core.h")

add_executable(core core.cc ${HEADER_LIST})

target_include_directories(core PUBLIC ../include/core)

source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})
