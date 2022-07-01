#include "lowest_common_ancestor_of_a_binary_search.h"

TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p,
                                         TreeNode* q) {
  if (root == nullptr) return nullptr;
  if (p->val > root->val && q->val > root->val)
    return lowestCommonAncestor(root->right, p, q);
  if (root->val > p->val && root->val > q->val)
    return lowestCommonAncestor(root->left, p, q);
  return root;
}