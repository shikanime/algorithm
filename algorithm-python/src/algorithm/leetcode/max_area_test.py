from .max_area import Solution


def test_solution():
    solver = Solution()
    assert solver.maxArea([1, 1]) == 1
    assert solver.maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7]) == 49
    assert solver.maxArea([2, 3, 4, 5, 18, 17, 6]) == 17
    assert solver.maxArea([1, 2, 1]) == 2
