
set (MIR_MODULE_DIRECTORY ${PROJECT_SOURCE_DIR}/sources/module/mir)
set (MIR_INCLUDE_DIRECTORY ${PROJECT_SOURCE_DIR}/sources/include/mir)

add_library(mir
    SHARED
)

GENERATE_EXPORT_HEADER(mir
    EXPORT_MACRO_NAME MIR_API
    EXPORT_FILE_NAME mir_api.hpp
)

target_sources(mir
PRIVATE
    type.cpp
PUBLIC
    FILE_SET CXX_MODULES
    BASE_DIRS
        ${MIR_MODULE_DIRECTORY}
    FILES
        ${MIR_MODULE_DIRECTORY}/mir-module.ixx
        ${MIR_MODULE_DIRECTORY}/generator.ixx

        ${MIR_MODULE_DIRECTORY}/type/type.ixx

        ${MIR_MODULE_DIRECTORY}/common/common-module.ixx
        ${MIR_MODULE_DIRECTORY}/common/index.ixx
        ${MIR_MODULE_DIRECTORY}/common/typehash.ixx
        ${MIR_MODULE_DIRECTORY}/common/this_type.ixx
        ${MIR_MODULE_DIRECTORY}/common/typelist.ixx

        ${MIR_MODULE_DIRECTORY}/function/function-module.ixx
        ${MIR_MODULE_DIRECTORY}/function/function-impl.ixx
        ${MIR_MODULE_DIRECTORY}/function/function-info.ixx
        ${MIR_MODULE_DIRECTORY}/function/function-iterator.ixx
        ${MIR_MODULE_DIRECTORY}/function/function-helper.ixx

        ${MIR_MODULE_DIRECTORY}/property/property-module.ixx
        ${MIR_MODULE_DIRECTORY}/property/property-enums.ixx
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
)

target_compile_definitions(mir
PRIVATE 
)