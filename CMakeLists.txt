

cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

project(mir LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_EXTENSIONS OFF)


find_package(Vulkan REQUIRED)

include (GenerateExportHeader)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(sources/src)
add_subdirectory(example)
