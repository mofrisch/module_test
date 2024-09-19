cmake_minimum_required(VERSION 3.29)

find_package(GTest REQUIRED)

enable_testing()


add_executable(log_test LogTest.cpp)
target_link_libraries(log_test PRIVATE log GTest::gtest GTest::gtest_main)

add_test(NAME log_test COMMAND log_test)