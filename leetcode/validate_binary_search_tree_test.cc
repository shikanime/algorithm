#include "validate_binary_search_tree.h"

#include <gtest/gtest.h>

TEST(ValidateBinarySearchTree, Base) {
  auto solution = Solution();
  EXPECT_EQ(solution.isValidBST(nullptr), true);
}

TEST(ValidateBinarySearchTree, SimpleTree) {
  auto solution = Solution();
  auto ir = TreeNode(3);
  auto il = TreeNode(1);
  auto input = TreeNode(2, &il, &ir);
  EXPECT_EQ(solution.isValidBST(&input), true);
}

TEST(ValidateBinarySearchTree, DeepValidTree) {
  auto solution = Solution();
  auto irr = TreeNode(6);
  auto irl = TreeNode(3);
  auto ir = TreeNode(4, &irl, &irr);
  auto il = TreeNode(1);
  auto input = TreeNode(5, &il, &ir);
  EXPECT_EQ(solution.isValidBST(&input), false);
}

TEST(ValidateBinarySearchTree, DuplicateNodes) {
  auto solution = Solution();
  auto ir = TreeNode(2);
  auto il = TreeNode(2);
  auto input = TreeNode(2, &il, &ir);
  EXPECT_EQ(solution.isValidBST(&input), false);
}
