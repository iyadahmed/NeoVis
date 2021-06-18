cmake_minimum_required(VERSION 3.2)

project(NeoVis)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin CACHE INTERNAL "" FORCE)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib CACHE INTERNAL "" FORCE)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -std=c99 -Wconversion -Wall -Wextra -pedantic")

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(IO_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/io)
set(JPGIO_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/jpgio)
set(IMAGE_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/image)
set(COMMON_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/common)
set(NODES_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/nodes)

include_directories(${IO_HEADERS_DIR})
include_directories(${JPGIO_HEADERS_DIR})
include_directories(${IMAGE_HEADERS_DIR})
include_directories(${COMMON_HEADERS_DIR})
include_directories(${NODES_HEADERS_DIR})

add_subdirectory(src)