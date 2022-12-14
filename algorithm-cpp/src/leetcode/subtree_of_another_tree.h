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
      auto [fp, fq] = queue.front();
      queue.pop();
      if (fp == nullptr && fq == nullptr) continue;
      if (fp == nullptr || fq == nullptr) return false;
      if (fp->val != fq->val) return false;
      queue.emplace(fp->left, fq->left);
      queue.emplace(fp->right, fq->right);
    }
    return true;
  }
};
}  // namespace leetcode::subtree_of_another_tree