#include <queue>
#include <vector>

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
  std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr) return {};
    std::vector<std::vector<int>> levels{{root->val}};
    std::queue<TreeNode*> rest({root->left, root->right});
    while (!rest.empty()) {
      std::vector<int> curr;
      for (auto i = rest.size(); i > 0; i--) {
        auto node = rest.front();
        rest.pop();
        if (node != nullptr) {
          curr.emplace_back(node->val);
          rest.emplace(node->left);
          rest.emplace(node->right);
        }
      }
      if (!curr.empty()) {
        levels.push_back(curr);
      }
    }
    return levels;
  }
};