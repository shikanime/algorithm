cmake_minimum_required(VERSION 3.10)
project(leetcode)

enable_testing()

find_package(GTest REQUIRED)

add_executable(same_tree same_tree.cc same_tree_test.cc)
set_property(TARGET same_tree PROPERTY CXX_STANDARD 20)
target_link_libraries(same_tree PRIVATE GTest::gtest_main)
gtest_discover_tests(same_tree)

add_executable(subtree_of_another_tree subtree_of_another_tree.cc
                                       subtree_of_another_tree_test.cc)
set_property(TARGET subtree_of_another_tree PROPERTY CXX_STANDARD 20)
target_link_libraries(subtree_of_another_tree PRIVATE GTest::gtest_main)
gtest_discover_tests(subtree_of_another_tree)
