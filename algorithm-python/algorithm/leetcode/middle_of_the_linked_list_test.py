from .middle_of_the_linked_list import ListNode, Solution


def test_solution():
    solver = Solution()
    data = solver.middleNode(
        ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5, ListNode(6))))))
    )
    assert isinstance(data, ListNode)
    assert data.val == 4
    assert isinstance(data.next, ListNode)
    assert data.next.val == 5
    assert isinstance(data.next.next, ListNode)
    assert data.next.next.val == 6
