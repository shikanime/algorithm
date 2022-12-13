#include "binary_tree_right_side_view.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace leetcode::binary_tree_right_side_view;

TEST(BinaryTreeRightSideView, Base) {
  auto solution = Solution();
  std::vector<int> output = {};
  EXPECT_EQ(solution.rightSideView(nullptr), output);
}

TEST(BinaryTreeRightSideView, OnlyRight) {
  auto solution = Solution();
  auto irr = TreeNode(5);
  auto ilr = TreeNode(4);
  auto il = TreeNode(2, nullptr, &ilr);
  auto ir = TreeNode(3, nullptr, &irr);
  auto input = TreeNode(1, &ir, &il);
  EXPECT_THAT(solution.rightSideView(&input),
              testing::ElementsAreArray({1, 2, 4}));
}