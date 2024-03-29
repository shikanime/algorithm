cmake_minimum_required(VERSION 3.10)

project(leetcode)

find_package(GTest REQUIRED)

add_executable(same_tree same_tree_test.cc)
set_property(TARGET same_tree PROPERTY CXX_STANDARD 20)
target_link_libraries(same_tree PRIVATE GTest::gtest_main)
gtest_discover_tests(same_tree)

add_executable(subtree_of_another_tree subtree_of_another_tree_test.cc)
set_property(TARGET subtree_of_another_tree PROPERTY CXX_STANDARD 20)
target_link_libraries(subtree_of_another_tree PRIVATE GTest::gtest_main)
gtest_discover_tests(subtree_of_another_tree)

add_executable(lowest_common_ancestor_of_a_binary_search
               lowest_common_ancestor_of_a_binary_search_test.cc)
set_property(TARGET lowest_common_ancestor_of_a_binary_search
             PROPERTY CXX_STANDARD 20)
target_link_libraries(lowest_common_ancestor_of_a_binary_search
                      PRIVATE GTest::gtest_main)
gtest_discover_tests(lowest_common_ancestor_of_a_binary_search)

add_executable(binary_tree_level_order_traversal
               binary_tree_level_order_traversal_test.cc)
set_property(TARGET binary_tree_level_order_traversal PROPERTY CXX_STANDARD 20)
target_link_libraries(binary_tree_level_order_traversal
                      PRIVATE GTest::gtest_main)
gtest_discover_tests(binary_tree_level_order_traversal)

add_executable(binary_tree_right_side_view binary_tree_right_side_view_test.cc)
set_property(TARGET binary_tree_right_side_view PROPERTY CXX_STANDARD 20)
target_link_libraries(binary_tree_right_side_view PRIVATE GTest::gtest_main)
gtest_discover_tests(binary_tree_right_side_view)

add_executable(count_good_nodes_in_binary_tree
               count_good_nodes_in_binary_tree_test.cc)
set_property(TARGET count_good_nodes_in_binary_tree PROPERTY CXX_STANDARD 20)
target_link_libraries(count_good_nodes_in_binary_tree PRIVATE GTest::gtest_main)
gtest_discover_tests(count_good_nodes_in_binary_tree)

add_executable(validate_binary_search_tree validate_binary_search_tree_test.cc)
set_property(TARGET validate_binary_search_tree PROPERTY CXX_STANDARD 20)
target_link_libraries(validate_binary_search_tree PRIVATE GTest::gtest_main)
gtest_discover_tests(validate_binary_search_tree)

add_executable(kth_smallest_element_in_a_bst
               kth_smallest_element_in_a_bst_test.cc)
set_property(TARGET kth_smallest_element_in_a_bst PROPERTY CXX_STANDARD 20)
target_link_libraries(kth_smallest_element_in_a_bst PRIVATE GTest::gtest_main)
gtest_discover_tests(kth_smallest_element_in_a_bst)
