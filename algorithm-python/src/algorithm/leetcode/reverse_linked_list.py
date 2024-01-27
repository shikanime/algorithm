from dataclasses import dataclass
from typing import Optional


@dataclass
class ListNode:
    val: int = 0
    next: Optional["ListNode"] = None


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        return self.traverse(head)

    def traverse(
        self, head: Optional[ListNode], acc: Optional[ListNode] = None
    ) -> Optional[ListNode]:
        if head is None:
            return acc
        return self.traverse(head.next, ListNode(head.val, acc))
