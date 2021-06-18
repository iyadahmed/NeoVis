set(SOURCE_FILES
    jpgio.h
    jpgio.c
)

find_package(TurboJPEG REQUIRED)
message(STATUS "TURBOJPEG_LIBRARY=${TURBOJPEG_LIBRARY}")
message(STATUS "TURBOJPEG_INCLUDE_DIR=${TURBOJPEG_INCLUDE_DIR}")

if(TARGET turbojpeg-static)
    set (_turbojpeg_target "turbojpeg-static")
else()
    set (_turbojpeg_target "turbojpeg")
endif()

add_library(jpgio SHARED STATIC ${SOURCE_FILES})

target_link_libraries(jpgio common image ${_turbojpeg_target})
target_include_directories(jpgio PUBLIC .)