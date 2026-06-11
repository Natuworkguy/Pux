cmake_minimum_required(VERSION 3.10)

project(pygame)

# Find Python automatically
find_package(Python3 REQUIRED COMPONENTS Development)

add_library(
    pygame
    SHARED
    src/pux_core.cpp
    src/pux_graphics.cpp
)

target_compile_definitions(
    pygame
    PRIVATE
    PUX_EXPORT
)

target_include_directories(
    pygame
    PRIVATE
    include
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