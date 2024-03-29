#include "subtree_of_another_tree.h"

#include <gtest/gtest.h>

using namespace leetcode::subtree_of_another_tree;

TEST(SubTree, Base) {
  auto solution = Solution();
  EXPECT_EQ(solution.isSubtree(nullptr, nullptr), true);
}

TEST(SubTree, Normal) {
  auto solution = Solution();

  auto lll = TreeNode(1);
  auto llr = TreeNode(2);
  auto ll = TreeNode(4, &lll, &llr);
  auto lr = TreeNode(5);
  auto l = TreeNode(3, &ll, &lr);

  auto rl = TreeNode(1);
  auto rr = TreeNode(2);
  auto r = TreeNode(4, &rl, &rr);

  EXPECT_EQ(solution.isSubtree(&l, &r), true);
}

TEST(SubTree, NonMediumTreeSubTree) {
  auto solution = Solution();

  auto lllr = TreeNode(0);
  auto llr = TreeNode(2, nullptr, &lllr);
  auto lll = TreeNode(1);
  auto lr = TreeNode(5);
  auto ll = TreeNode(4, &lll, &llr);
  auto l = TreeNode(3, &ll, &lr);

  auto rl = TreeNode(1);
  auto rr = TreeNode(2);
  auto r = TreeNode(4, &rl, &rr);

  EXPECT_EQ(solution.isSubtree(&l, &r), false);
}
