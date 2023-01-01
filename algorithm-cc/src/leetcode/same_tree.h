#include <queue>

namespace leetcode::same_tree {
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
}  // namespace leetcode::same_tree