from .contains_duplicate import Solution


def test_solution():
    solver = Solution()
    assert solver.containsDuplicate([1, 2, 3, 1]) == True
