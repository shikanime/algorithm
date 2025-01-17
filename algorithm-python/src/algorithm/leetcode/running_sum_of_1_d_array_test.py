from .running_sum_of_1_d_array import Solution


def test_solution():
    solver = Solution()
    assert solver.runningSum([1, 2, 3, 4]) == [1, 3, 6, 10]
