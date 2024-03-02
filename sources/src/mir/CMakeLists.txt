
set (MIR_MODULE_DIRECTORY ${PROJECT_SOURCE_DIR}/sources/module/mir)
set (MIR_INCLUDE_DIRECTORY ${PROJECT_SOURCE_DIR}/sources/include/mir)

add_library(mir
    mir.cpp
    function.cpp
    property.cpp
)

target_sources(mir
PUBLIC
    FILE_SET CXX_MODULES
    BASE_DIRS
        ${MIR_MODULE_DIRECTORY}
    FILES
        ${MIR_MODULE_DIRECTORY}/mir.ixx
        ${MIR_MODULE_DIRECTORY}/generator.ixx

        ${MIR_MODULE_DIRECTORY}/common/common.ixx
        ${MIR_MODULE_DIRECTORY}/common/index.ixx
        ${MIR_MODULE_DIRECTORY}/common/typehash.ixx
        ${MIR_MODULE_DIRECTORY}/common/this_type.ixx
        ${MIR_MODULE_DIRECTORY}/common/typelist.ixx

        ${MIR_MODULE_DIRECTORY}/function/function.ixx
        ${MIR_MODULE_DIRECTORY}/function/function-impl.ixx
        ${MIR_MODULE_DIRECTORY}/function/function-info.ixx
        ${MIR_MODULE_DIRECTORY}/function/function-iterator.ixx
        ${MIR_MODULE_DIRECTORY}/function/function-helper.ixx

        ${MIR_MODULE_DIRECTORY}/property/property.ixx
        ${MIR_MODULE_DIRECTORY}/property/property-impl.ixx
        ${MIR_MODULE_DIRECTORY}/property/property-info.ixx
        ${MIR_MODULE_DIRECTORY}/property/property-iterator.ixx
        ${MIR_MODULE_DIRECTORY}/property/property-helper.ixx

)


target_include_directories(mir
PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}/
    ${CMAKE_SOURCE_DIR}/sources/include/mir
    ${CMAKE_SOURCE_DIR}/sources/modules/mir
)


target_link_libraries(mir
PUBLIC

PRIVATE
)

target_compile_options(mir
PUBLIC
    ${DEFAULT_COMPILE_OPTIONS}
)

target_compile_definitions(mir
PRIVATE 
    ${DEFAULT_COMPILE_DEFINITIONS}
)