class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        memo: dict[int, int] = {}

        for i, n in enumerate(nums):
            diff = target - n
            if diff in memo:
                return [memo[diff], i]
            memo[n] = i

        raise ValueError("No solution")
