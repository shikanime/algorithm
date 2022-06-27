from .binary_search import Solution


def test_solution():
    solver = Solution()
    assert solver.search([-1, 0, 3, 5, 9, 12], 9) == 4
    # assert solver.search([-1, 0, 3, 5, 9, 12], 2) == -1
