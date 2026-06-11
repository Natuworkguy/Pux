cmake_minimum_required(VERSION 3.10)

project(pygame)

# Find Python automatically
find_package(Python3 REQUIRED COMPONENTS Development)

add_library(
    pygame
    SHARED
    wrapper.cpp
)

target_include_directories(
    pygame
    PRIVATE
    ${Python3_INCLUDE_DIRS}
)

target_link_libraries(
    pygame
    PRIVATE
    Python3::Python
)

set_target_properties(
    pygame
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY
    "${CMAKE_BINARY_DIR}/output"
)