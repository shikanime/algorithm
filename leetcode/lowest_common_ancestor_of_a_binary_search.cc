#include "lowest_common_ancestor_of_a_binary_search.h"

TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p,
                                         TreeNode* q) {
  while (root != nullptr)
    if (p->val > root->val && q->val > root->val)
      root = root->right;
     else if (root->val > p->val && root->val > q->val)
      root = root->left;
     else
      return root;
  return nullptr;
}