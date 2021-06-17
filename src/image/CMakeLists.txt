cmake_minimum_required(VERSION 3.2)
project(image C)

set(SOURCE_FILES
    image.h
    image.c
)

add_library(image SHARED STATIC ${SOURCE_FILES})

install(TARGETS image DESTINATION ${NEOVIS_INSTALL_LIB_DIR})
install(FILES image.h DESTINATION ${NEOVIS_INSTALL_INCLUDE_DIR})
