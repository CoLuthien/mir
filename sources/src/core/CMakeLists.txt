
add_library(core
    core.cpp
)

set (CORE_INCLUDE_DIRECTORY ${PROJECT_SOURCE_DIR}/sources/include/core)
set (CORE_MODULE_DIRECTORY ${PROJECT_SOURCE_DIR}/sources/module/core)

GENERATE_EXPORT_HEADER(core
    EXPORT_MACRO_NAME CORE_API
    EXPORT_FILE_NAME core_api.hpp
)

target_sources(core
PUBLIC
    FILE_SET CXX_MODULES
    BASE_DIRS
        ${CORE_MODULE_DIRECTORY}
    FILES
)


target_include_directories(core
PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}/
    ${CMAKE_SOURCE_DIR}/sources/include
    ${CMAKE_SOURCE_DIR}/sources/modules
    ${CORE_INCLUDE_DIRECTORY}
PRIVATE
)


target_link_libraries(core
PUBLIC
PRIVATE
)

target_compile_options(core
PUBLIC
    ${DEFAULT_COMPILE_OPTIONS}
)

target_compile_definitions(core
PRIVATE 
    ${DEFAULT_COMPILE_DEFINITIONS}
)