#include "binary_tree_right_side_view.h"

#include <gtest/gtest.h>

TEST(BinaryTreeRightSideView, Base) {
  auto solution = Solution();
  std::vector<int> output = {};
  EXPECT_EQ(output, solution.rightSideView(nullptr));
}

TEST(BinaryTreeRightSideView, OnlyRight) {
  auto solution = Solution();
  std::vector<int> output = {1, 3, 4};
  auto irr = TreeNode(5);
  auto ilr = TreeNode(4);
  auto il = TreeNode(2, nullptr, &ilr);
  auto ir = TreeNode(3, nullptr, &irr);
  auto input = TreeNode(1, &ir, &il);
  EXPECT_EQ(output, solution.rightSideView(&input));
}