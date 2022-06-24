class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        if target == 0:
            return []
        for idx, num in enumerate(nums):
            try:
                solution = self.twoSum(
                    nums[0:idx] + nums[idx + 1 :],
                    target - num,
                )
            except ValueError:
                continue
            return [idx, *list(map(lambda x: x + 1, solution))]
        raise ValueError("No solution")


solver = Solution()
print(solver.twoSum([2, 7, 11, 15], 9))
print(solver.twoSum([3, 2, 4], 6))
print(solver.twoSum([3, 3], 6))
print(solver.twoSum([-2, -2], -4))
print(solver.twoSum([-3, 4, 3, 90], 0))
