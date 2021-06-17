cmake_minimum_required(VERSION 3.2)
project(NeoVis-src)

add_subdirectory(io)
add_subdirectory(jpgio)
add_subdirectory(image)
add_subdirectory(common)
add_subdirectory(nodes)
set(SOURCE_FILES main.c)

add_executable(NeoVis ${SOURCE_FILES})

find_package(TurboJPEG REQUIRED)
message(STATUS "TURBOJPEG_LIBRARY=${TURBOJPEG_LIBRARY}")
message(STATUS "TURBOJPEG_INCLUDE_DIR=${TURBOJPEG_INCLUDE_DIR}")

if(TARGET turbojpeg-static)
    set (_turbojpeg_target "turbojpeg-static")
else()
    set (_turbojpeg_target "turbojpeg")
endif()

# target_link_libraries(NeoVis ${_turbojpeg_target})


target_link_libraries(NeoVis io jpgio image common nodes ${_turbojpeg_target})
install(TARGETS NeoVis DESTINATION ${NEOVIS_INSTALL_BIN_DIR})
