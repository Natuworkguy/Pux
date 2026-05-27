cmake_minimum_required(VERSION 3.10)

project(pygame_bindings)

# Find Python automatically
find_package(Python3 REQUIRED COMPONENTS Development)

add_library(
    pygame_bindings
    SHARED
    wrapper.cpp
)

target_include_directories(
    pygame_bindings
    PRIVATE
    ${Python3_INCLUDE_DIRS}
)

target_link_libraries(
    pygame_bindings
    PRIVATE
    Python3::Python
)

set_target_properties(
    pygame_bindings
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY
    "${CMAKE_BINARY_DIR}/output"
)