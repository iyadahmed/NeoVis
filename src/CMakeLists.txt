add_subdirectory(io)
add_subdirectory(image)
add_subdirectory(common)
add_subdirectory(nodes)

add_executable(neovis main.c)

target_link_libraries(neovis io image common nodes)