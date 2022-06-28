from dataclasses import dataclass
from typing import Optional, Tuple


@dataclass
class TreeNode:
    val: int = 0
    left: Optional["TreeNode"] = None
    right: Optional["TreeNode"] = None


class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        _, diameter = self.traverse(root)
        return diameter

    def traverse(self, root: Optional[TreeNode]) -> Tuple[int, int]:
        if not root:
            return -1, 0
        rheight, rdiameter = self.traverse(root.right)
        lheight, ldiameter = self.traverse(root.left)
        return (
            max(rheight, lheight) + 1,
            max(rdiameter, ldiameter, 2 + lheight + rheight),
        )
