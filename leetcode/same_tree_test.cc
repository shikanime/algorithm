#include "same_tree.h"

#include <gtest/gtest.h>

TEST(SameTree, Base) {
  auto solution = Solution();
  EXPECT_EQ(true, solution.isSameTree(nullptr, nullptr));
}

TEST(SameTree, Normal) {
  auto solution = Solution();
  auto left = TreeNode(0);
  EXPECT_EQ(false, solution.isSameTree(&left, nullptr));
}
