#include "binary_tree_level_order_traversal.h"

#include <gtest/gtest.h>

TEST(BinaryTreeLevelOrderTraversal, Base) {
  auto solution = Solution();
  std::vector<std::vector<int>> output = {};
  EXPECT_EQ(solution.levelOrder(nullptr), output);
}

TEST(BinaryTreeLevelOrderTraversal, SingleEntry) {
  auto solution = Solution();
  auto input = TreeNode(0);
  std::vector<std::vector<int>> output = {{0}};
  EXPECT_EQ(solution.levelOrder(&input), output);
}

TEST(BinaryTreeLevelOrderTraversal, MultipleLevel) {
  auto solution = Solution();
  auto ilr = TreeNode(2);
  auto il = TreeNode(2, &ilr, nullptr);
  auto ir = TreeNode(1);
  auto input = TreeNode(0, &ir, &il);
  std::vector<std::vector<int>> output = {{0}, {1, 2}, {2}};
  EXPECT_EQ(solution.levelOrder(&input), output);
}

TEST(BinaryTreeLevelOrderTraversal, DeepRightTree) {
  auto solution = Solution();
  auto irrrr = TreeNode(4);
  auto irrr = TreeNode(3, &irrrr, nullptr);
  auto irr = TreeNode(2, &irrr, nullptr);
  auto ir = TreeNode(1, &irr, nullptr);
  auto input = TreeNode(0, &ir, nullptr);
  std::vector<std::vector<int>> output = {{0}, {1}, {2}, {3}, {4}};
  EXPECT_EQ(solution.levelOrder(&input), output);
}

TEST(BinaryTreeLevelOrderTraversal, ZigZag) {
  auto solution = Solution();
  auto irlrr = TreeNode(4);
  auto irlr = TreeNode(3, &irlrr, nullptr);
  auto irr = TreeNode(2, nullptr, &irlr);
  auto ir = TreeNode(1, &irr, nullptr);
  auto input = TreeNode(0, &ir, nullptr);
  std::vector<std::vector<int>> output = {{0}, {1}, {2}, {3}, {4}};
  EXPECT_EQ(solution.levelOrder(&input), output);
}
