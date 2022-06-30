#include "same_tree.h"

#include <queue>

bool Solution::isSameTree(TreeNode* p, TreeNode* q) {
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
