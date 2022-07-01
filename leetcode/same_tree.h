#include <queue>

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
  bool isSameTree(TreeNode* p, TreeNode* q) {
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