from .two_sum_2 import Solution


def test_solution():
    solver = Solution()
    assert solver.twoSum([2, 7, 11, 15], 9) == [1, 2]
