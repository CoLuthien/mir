

add_executable(example
    main.cpp
)

target_link_libraries(example
PUBLIC
    mir
    object
    core
)
target_include_directories(example 
PUBLIC
    ${MIR_INCLUDE_DIRECTORY}
)