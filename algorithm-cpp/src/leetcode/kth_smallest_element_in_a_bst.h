#include <optional>
#include <utility>
#include <iostream>

namespace leetcode::kth_smallest_element_in_a_bst {
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
  int kthSmallest(TreeNode* root, int k) {
    auto [node, count] = traverse(root, k);
    if (node != nullptr) return node->val;
    return -1;
  }

 private:
  std::pair<TreeNode*, int> traverse(TreeNode* root, int k) {
    if (root == nullptr) return {nullptr, k};
    auto [node, count] = traverse(root->left, k);
    if (node != nullptr) return {node, count};
    if (count - 1 == 0) return {root, count};
    return traverse(root->right, count - 1);
  }
};
}  // namespace leetcode::kth_smallest_element_in_a_bst