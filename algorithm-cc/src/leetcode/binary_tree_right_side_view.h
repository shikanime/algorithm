#include <optional>
#include <queue>
#include <vector>

namespace leetcode::binary_tree_right_side_view {
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
  std::vector<int> rightSideView(TreeNode* root) const {
    if (root == nullptr) return {};
    std::vector<int> view{{root->val}};
    std::queue<TreeNode*> rest({root->left, root->right});
    while (!rest.empty()) {
      std::optional<int> curr = std::nullopt;
      for (auto i = rest.size(); i > 0; i--) {
        auto node = rest.front();
        rest.pop();
        if (node != nullptr) {
          curr = node->val;
          rest.emplace(node->left);
          rest.emplace(node->right);
        }
      }
      if (curr.has_value()) {
        view.emplace_back(curr.value());
      }
    }
    return view;
  }
};
}  // namespace leetcode::binary_tree_right_side_view