class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        memo: dict[int, int] = {}

        for i, n in enumerate(nums):
            diff = target - n
            if diff in memo:
                return [memo[diff], i]
            memo[n] = i

        raise Exception("No solution")


solver = Solution()
print(solver.twoSum([2, 7, 11, 15], 9))
print(solver.twoSum([3, 2, 4], 6))
print(solver.twoSum([3, 3], 6))
print(solver.twoSum([-2, -2], -4))
print(solver.twoSum([-3, 4, 3, 90], 0))
