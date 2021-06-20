set(SOURCE_FILES
    jpgio.h
    jpgio.c
)

find_package(TurboJPEG REQUIRED)
message(STATUS "TURBOJPEG_LIBRARY=${TurboJPEG_LIBRARIES}")
message(STATUS "TURBOJPEG_INCLUDE_DIR=${TurboJPEG_INCLUDE_DIRS}")

add_library(jpgio ${SOURCE_FILES})

target_link_libraries(jpgio common image ${TurboJPEG_LIBRARIES})
target_include_directories(jpgio PUBLIC .)