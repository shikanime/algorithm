#include <queue>

namespace leetcode::subtree_of_another_tree {
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
  bool isSubtree(TreeNode* root, TreeNode* subRoot) const {
    auto queue = std::queue<TreeNode*>();
    queue.emplace(root);
    while (!queue.empty()) {
      auto node = queue.front();
      queue.pop();
      if (node == nullptr) continue;
      if (isSameTree(node, subRoot)) return true;
      queue.emplace(node->left);
      queue.emplace(node->right);
    }
    return root == subRoot;
  }

 private:
  bool isSameTree(TreeNode* p, TreeNode* q) const {
    auto queue = std::queue<std::pair<TreeNode*, TreeNode*>>();
    queue.emplace(p, q);
    while (!queue.empty()) {
      auto [p, q] = queue.front();
      queue.pop();
      if (p == nullptr && q == nullptr) continue;
      if (p == nullptr || q == nullptr) return false;
      if (p->val != q->val) return false;
      queue.emplace(p->left, q->left);
      queue.emplace(p->right, q->right);
    }
    return true;
  }
};
}  // namespace leetcode::subtree_of_another_tree