cmake_minimum_required(VERSION 3.2)
project(jpgio C)

set(SOURCE_FILES
    jpgio.h
    jpgio.c
)

add_library(jpgio SHARED STATIC ${SOURCE_FILES})

install(TARGETS jpgio DESTINATION ${NEOVIS_INSTALL_LIB_DIR})
install(FILES jpgio.h DESTINATION ${NEOVIS_INSTALL_INCLUDE_DIR})
