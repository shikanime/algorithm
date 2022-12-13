#include "lowest_common_ancestor_of_a_binary_search.h"

#include <gtest/gtest.h>

using namespace leetcode::lowest_common_ancestor_of_a_binary_search;

TEST(LowestCommonAncestorOfABinarySearch, Base) {
  auto solution = Solution();
  EXPECT_EQ(solution.lowestCommonAncestor(nullptr, nullptr, nullptr), nullptr);
}
