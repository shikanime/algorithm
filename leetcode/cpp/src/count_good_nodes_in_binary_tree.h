#include <algorithm>

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
}  // namespace