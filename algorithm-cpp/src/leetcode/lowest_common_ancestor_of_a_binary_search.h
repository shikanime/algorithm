#include <utility>

namespace leetcode::lowest_common_ancestor_of_a_binary_search {
struct TreeNode {
  int val = 0;
  TreeNode* left = nullptr;
  TreeNode* right = nullptr;
  explicit TreeNode(int x) : val(x) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode const* p,
                                 TreeNode const* q) {
    while (root != nullptr)
      if (p->val > root->val && q->val > root->val)
        root = root->right;
      else if (root->val > p->val && root->val > q->val)
        root = root->left;
      else
        return root;
    return nullptr;
  }
};
}  // namespace leetcode::lowest_common_ancestor_of_a_binary_search