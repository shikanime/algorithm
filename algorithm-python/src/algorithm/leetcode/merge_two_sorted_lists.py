from dataclasses import dataclass
from typing import Optional


@dataclass
class ListNode:
    val: int = 0
    next: Optional["ListNode"] = None


class Solution:
    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        return self.traverse(list1, list2)

    def traverse(
        self,
        list1: Optional[ListNode],
        list2: Optional[ListNode],
        acc: Optional[ListNode] = None,
    ) -> Optional[ListNode]:
        if list1 is not None and list2 is not None:
            if list1.val >= list2.val:
                return ListNode(list2.val, self.traverse(list1, list2.next, acc))
            else:
                return ListNode(list1.val, self.traverse(list1.next, list2, acc))
        elif list1 is not None:
            return list1
        elif list2 is not None:
            return list2
        return acc
