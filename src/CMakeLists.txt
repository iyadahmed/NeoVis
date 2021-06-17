cmake_minimum_required(VERSION 3.2)
project(NeoVis-src)

add_subdirectory(io)
add_subdirectory(jpgio)
add_subdirectory(image)
add_subdirectory(common)
add_subdirectory(nodes)
set(SOURCE_FILES main.c)

add_executable(NeoVis ${SOURCE_FILES})

target_link_libraries(NeoVis io jpgio image common nodes)
install(TARGETS NeoVis DESTINATION ${NEOVIS_INSTALL_BIN_DIR})
