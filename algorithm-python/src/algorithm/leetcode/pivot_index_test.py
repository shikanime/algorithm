from .pivot_index import Solution


def test_solution():
    solver = Solution()
    assert solver.pivotIndex([1, 7, 3, 6, 5, 6]) == 3
    assert solver.pivotIndex([2, 1, -1]) == 0
