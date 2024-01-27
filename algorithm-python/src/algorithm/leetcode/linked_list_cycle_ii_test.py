from .linked_list_cycle_ii import ListNode, Solution


def test_solution():
    solver = Solution()
    data = ListNode(3, ListNode(2, ListNode(0, ListNode(-4))))
    data.next.next.next.next = data.next
    data = solver.detectCycle(data)
    assert isinstance(data, ListNode)
    assert data.val == 2

    data = solver.detectCycle(ListNode(1, ListNode(2)))
    assert data == None
