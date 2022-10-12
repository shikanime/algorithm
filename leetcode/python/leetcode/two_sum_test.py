from .two_sum import Solution


def test_solution():
    solver = Solution()
    assert solver.twoSum([2, 7, 11, 15], 9) == [0, 1]
    assert solver.twoSum([3, 2, 4], 6) == [1, 2]
    assert solver.twoSum([3, 3], 6) == [0, 1]
    assert solver.twoSum([-2, -2], -4) == [0, 1]
    assert solver.twoSum([-3, 4, 3, 90], 0) == [0, 2]
