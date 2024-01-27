from dataclasses import dataclass
from typing import Optional


@dataclass
class ListNode:
    val: int = 0
    next: Optional["ListNode"] = None


class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        second = self.reverse(self.disconnect(self.middle(head)))
        self.interleave(head, second)

    def disconnect(self, head: Optional[ListNode]):
        if not head:
            return None
        cursor = head.next
        head.next = None
        return cursor

    def middle(self, head: Optional[ListNode]):
        if not head:
            return None
        slow, fast = head, head.next
        while slow and fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow

    def reverse(self, head: Optional[ListNode]):
        cursor = head
        prev = None
        while cursor:
            tmp = cursor.next
            cursor.next = prev
            prev = cursor
            cursor = tmp
        return prev

    def interleave(self, a: Optional[ListNode], b: Optional[ListNode]):
        while a and b:
            tmpa, tmpb = a.next, b.next
            a.next = b
            b.next = tmpa
            a, b = tmpa, tmpb
