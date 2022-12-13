#include <algorithm>

namespace leetcode::count_good_nodes_in_binary_tree {
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
  int goodNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    return traverse(root, root->val);
  }

 private:
  int traverse(TreeNode* root, int limit) {
    if (root == nullptr) return 0;
    auto curr = std::max(limit, root->val);
    auto res = root->val >= limit ? 1 : 0;
    res += traverse(root->left, curr);
    res += traverse(root->right, curr);
    return res;
  }
};
}  // namespace leetcode::count_good_nodes_in_binary_tree