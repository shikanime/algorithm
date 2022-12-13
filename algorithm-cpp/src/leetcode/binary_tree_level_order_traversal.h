#include <queue>
#include <vector>

namespace leetcode::binary_tree_level_order_traversal {
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
  std::vector<std::vector<int>> levelOrder(TreeNode* root) const {
    if (root == nullptr) return {};
    std::vector<std::vector<int>> levels{{root->val}};
    std::queue<TreeNode*> rest({root->left, root->right});
    while (!rest.empty()) {
      levels.emplace_back();
      auto& curr = levels.back();
      for (auto i = rest.size(); i > 0; i--) {
        auto node = rest.front();
        rest.pop();
        if (node != nullptr) {
          curr.emplace_back(node->val);
          rest.emplace(node->left);
          rest.emplace(node->right);
        }
      }
      if (curr.empty()) {
        levels.pop_back();
      }
    }
    return levels;
  }
};
}  // namespace