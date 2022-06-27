class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        memo: dict[int, int] = {}

        for i, n in enumerate(nums):
            diff = target - n
            if diff in memo:
                return [memo[diff], i]
            memo[n] = i

        raise ValueError("No solution")


def test_solution():
    solver = Solution()
    assert solver.twoSum([2, 7, 11, 15], 9) == [0, 1]
    assert solver.twoSum([3, 2, 4], 6) == [1, 2]
    assert solver.twoSum([3, 3], 6) == [0, 1]
    assert solver.twoSum([-2, -2], -4) == [0, 1]
    assert solver.twoSum([-3, 4, 3, 90], 0) == [0, 2]
