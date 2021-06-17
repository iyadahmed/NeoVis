cmake_minimum_required(VERSION 3.2)

set(SOURCE_FILES
    common.h
    common.c
)

add_library(common SHARED STATIC ${SOURCE_FILES})

install(TARGETS common DESTINATION ${NEOVIS_INSTALL_LIB_DIR})
install(FILES common.h DESTINATION ${NEOVIS_INSTALL_INCLUDE_DIR})
