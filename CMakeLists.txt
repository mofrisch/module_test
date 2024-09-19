# file: ./CMakeLists.txt

cmake_minimum_required(VERSION 3.28)
project(cpp_modules_test LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_EXTENSIONS OFF)  # This ensures that only standard C++ is used, not GNU extensions
add_compile_options(-Wall -Wextra -Wpedantic)

find_package(GTest REQUIRED)

include(modules.cmake)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(main src/main.cpp)
add_module(log src/log.cppm)
target_link_libraries(log PRIVATE std)

target_link_libraries(main PRIVATE log)

add_executable(log_test tests/LogTest.cpp)
target_link_libraries(log_test PRIVATE gtest gtest_main std log)

add_test(NAME LOG_TEST COMMAND log_test)