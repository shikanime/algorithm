#include "same_tree.h"

#include <gtest/gtest.h>

TEST(SameTree, SolutionAssertions) {
  auto solution = Solution();
  EXPECT_EQ(true, solution.isSameTree(nullptr, nullptr));
  auto left = TreeNode(0);
  EXPECT_EQ(false, solution.isSameTree(&left, nullptr));
}
