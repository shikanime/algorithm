#include "same_tree.h"

#include <gtest/gtest.h>

using namespace leetcode::same_tree;

TEST(SameTree, Base) {
  auto solution = Solution();
  EXPECT_EQ(solution.isSameTree(nullptr, nullptr), true);
}

TEST(SameTree, Normal) {
  auto solution = Solution();
  auto left = TreeNode(0);
  EXPECT_EQ(solution.isSameTree(&left, nullptr), false);
}
