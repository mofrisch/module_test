# file: ./CMakeLists.txt

cmake_minimum_required(VERSION 3.28)
project(cpp_modules_test)

include(modules.cmake)

add_executable(main src/main.cpp)
add_module(greeter src/greeter.cppm)
target_link_libraries(greeter PRIVATE std)

target_link_libraries(main PRIVATE greeter)
