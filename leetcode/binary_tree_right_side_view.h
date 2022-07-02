#include <queue>
#include <vector>
#include <optional>

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
  std::vector<int> rightSideView(TreeNode* root) {
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