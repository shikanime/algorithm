#include <optional>
#include <utility>
#include <iostream>

namespace {
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
}  // namespace