#include "kth_smallest_element_in_a_bst.h"

#include <gtest/gtest.h>

using namespace leetcode::kth_smallest_element_in_a_bst;

TEST(KthSmallestElementInABst, Base) {
  auto solution = Solution();
  auto input = TreeNode(1);
  EXPECT_EQ(solution.kthSmallest(&input, 1), 1);
}
