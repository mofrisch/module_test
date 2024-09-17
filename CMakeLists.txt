# file: ./CMakeLists.txt

cmake_minimum_required(VERSION 3.28)
project(cpp_modules_test LANGUAGES CXX)

find_package(GTest REQUIRED)

include(modules.cmake)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(main src/main.cpp)
add_module(greeter src/greeter.cppm)
target_link_libraries(greeter PRIVATE std)

target_link_libraries(main PRIVATE greeter)

# enable_testing()
add_subdirectory(tests)
