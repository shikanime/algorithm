#include <optional>

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
  bool isValidBST(TreeNode* root) {
    if (root == nullptr) return true;
    return traverse(root, std::nullopt, std::nullopt);
  }

 private:
  bool traverse(TreeNode* root, std::optional<int> left,
                std::optional<int> right) {
    if (root == nullptr) return true;
    if ((left.has_value() && left >= root->val) ||
        (right.has_value() && root->val >= right))
      return false;
    return traverse(root->left, left, {root->val}) &&
           traverse(root->right, {root->val}, right);
  }
};
}  // namespace