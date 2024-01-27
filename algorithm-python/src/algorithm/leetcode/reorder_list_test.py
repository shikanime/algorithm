from .reorder_list import ListNode, Solution


def test_solution():
    solver = Solution()
    data = ListNode(1, ListNode(2, ListNode(3, ListNode(4, None))))
    solver.reorderList(data)
    assert isinstance(data, ListNode)
    assert data.val == 1
    assert isinstance(data.next, ListNode)
    assert data.next.val == 4
    assert isinstance(data.next.next, ListNode)
    assert data.next.next.val == 2
    assert isinstance(data.next.next.next, ListNode)
    assert data.next.next.next.val == 3
