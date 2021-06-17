cmake_minimum_required(VERSION 3.2)
project(nodes C)

set(SOURCE_FILES
    nodes.h
    nodes.c
)

add_library(nodes SHARED STATIC ${SOURCE_FILES})

install(TARGETS nodes DESTINATION ${NEOVIS_INSTALL_LIB_DIR})
install(FILES nodes.h DESTINATION ${NEOVIS_INSTALL_INCLUDE_DIR})
