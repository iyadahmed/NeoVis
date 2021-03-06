cmake_minimum_required(VERSION 3.2)

project(NeoVis)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin CACHE INTERNAL "" FORCE)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib CACHE INTERNAL "" FORCE)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

set(CMAKE_C_STANDARD 99)
if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    add_compile_options("-O2")
    add_compile_options("-Wconversion")
    add_compile_options("-Wall")
    add_compile_options("-Wextra")
    add_compile_options("-pedantic")
    add_compile_options("-Wcast-align")
    add_compile_options("-Werror=vla")
    add_compile_options("-Wstrict-prototypes")
    add_compile_options("-Wmissing-prototypes")
    add_compile_options("-Wno-char-subscripts")
    add_compile_options("-Wno-unknown-pragmas")
    add_compile_options("-Wpointer-arith")
    add_compile_options("-Wunused-parameter")
    add_compile_options("-Wwrite-strings")
    add_compile_options("-Wlogical-op")
    add_compile_options("-Wundef")
    add_compile_options("-Winit-self")
    add_compile_options("-Wmissing-include-dirs")
    add_compile_options("-Wno-div-by-zero")
elseif(MSVC)
    # Warning level 3
    add_compile_options("/W3")
    # Disable fopen warning etc.
    add_compile_options("/wd4996")
endif()

add_subdirectory(src)