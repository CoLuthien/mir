

set (OBJECT_INCLUDE_DIRECTORY ${PROJECT_SOURCE_DIR}/sources/include/object)
set (OBJECT_MODULE_DIRECTORY ${PROJECT_SOURCE_DIR}/sources/module/object)
set (OBJECT_SOURCE_DIRECTORY ${PROJECT_SOURCE_DIR}/sources/src/object)

add_library(object
    SHARED 
)

GENERATE_EXPORT_HEADER(object
    EXPORT_MACRO_NAME OBJECT_API
    EXPORT_FILE_NAME object_api.hpp
)
target_sources(object
PRIVATE
    ${OBJECT_SOURCE_DIRECTORY}/field.cpp

PUBLIC
    FILE_SET CXX_MODULES
    BASE_DIRS
        ${OBJECT_MODULE_DIRECTORY}
    FILES
        ${OBJECT_MODULE_DIRECTORY}/module.ixx

        ${OBJECT_MODULE_DIRECTORY}/field.ixx

        ${OBJECT_MODULE_DIRECTORY}/object.ixx

        ${OBJECT_MODULE_DIRECTORY}/type.ixx



)


target_include_directories(object
PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}/
    ${CMAKE_SOURCE_DIR}/sources/include
    ${CMAKE_SOURCE_DIR}/sources/include/object
PRIVATE
    ${OBJECT_INCLUDE_DIRECTORY}
)


target_link_libraries(object
PUBLIC
    core
    mir

PRIVATE
)

target_compile_options(object
PUBLIC
)

target_compile_definitions(object
PRIVATE 
)