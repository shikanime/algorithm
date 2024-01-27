from .reverse_linked_list import ListNode, Solution


def test_solution():
    solver = Solution()
    data = solver.reverseList(ListNode(0, ListNode(1, ListNode(2, ListNode(3, None)))))
    assert isinstance(data, ListNode)
    assert data.val == 3
    assert isinstance(data.next, ListNode)
    assert data.next.val == 2
    assert isinstance(data.next.next, ListNode)
    assert data.next.next.val == 1
    assert isinstance(data.next.next.next, ListNode)
    assert data.next.next.next.val == 0
