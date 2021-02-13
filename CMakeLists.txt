cmake_minimum_required(VERSION 3.0)

project(gtk_test1)

find_package(SFML REQUIRED COMPONENTS window graphics system audio network )

include_directories(${SFML_INCLUDE_DIR})

add_executable(gtk_test1 main.cpp)

install(TARGETS gtk_test1 RUNTIME DESTINATION bin)

target_link_libraries(gtk_test1 sfml-window sfml-graphics sfml-system sfml-audio sfml-network) 

