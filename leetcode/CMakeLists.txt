cmake_minimum_required(VERSION 3.10)
project (leetcode)

add_executable(same_tree same_tree.cc same_tree_test.cc)
set_property(TARGET same_tree PROPERTY CXX_STANDARD 20)
target_link_libraries(same_tree PRIVATE GTest::gtest_main)
gtest_discover_tests(same_tree)
