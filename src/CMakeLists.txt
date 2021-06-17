add_subdirectory(io)
add_subdirectory(jpgio)
add_subdirectory(image)
add_subdirectory(common)
add_subdirectory(nodes)
set(SOURCE_FILES main.c)

add_executable(neovis ${SOURCE_FILES})

target_link_libraries(neovis io jpgio image common nodes)
install(TARGETS neovis DESTINATION ${NEOVIS_INSTALL_BIN_DIR})
