#include "count_good_nodes_in_binary_tree.h"

#include <gtest/gtest.h>

using namespace leetcode::count_good_nodes_in_binary_tree;

TEST(CountGoodNodesInBinaryTree, Base) {
  auto solution = Solution();
  EXPECT_EQ(solution.goodNodes(nullptr), 0);
}

TEST(CountGoodNodesInBinaryTree, SingleEntry) {
  auto solution = Solution();
  auto input = TreeNode(1);
  EXPECT_EQ(solution.goodNodes(&input), 1);
}

TEST(CountGoodNodesInBinaryTree, MultiLevelWithMiddleLowerTree) {
  auto solution = Solution();
  auto ilr = TreeNode(4);
  auto ir = TreeNode(1);
  auto il = TreeNode(2, &ilr, nullptr);
  auto input = TreeNode(3, &ir, &il);
  EXPECT_EQ(solution.goodNodes(&input), 2);
}

TEST(CountGoodNodesInBinaryTree, BadMiddleTree) {
  auto solution = Solution();
  auto ilr = TreeNode(5);
  auto ill = TreeNode(1);
  auto irl = TreeNode(3);
  auto ir = TreeNode(1, &irl, nullptr);
  auto il = TreeNode(4, &ilr, &ill);
  auto input = TreeNode(3, &ir, &il);
  EXPECT_EQ(solution.goodNodes(&input), 4);
}

TEST(CountGoodNodesInBinaryTree, SingleBadEnded) {
  auto solution = Solution();
  auto irr = TreeNode(2);
  auto irl = TreeNode(4);
  auto ir = TreeNode(3, &irl, &irr);
  auto input = TreeNode(3, &ir, nullptr);
  EXPECT_EQ(solution.goodNodes(&input), 3);
}