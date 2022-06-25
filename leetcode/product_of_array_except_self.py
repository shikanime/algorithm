class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        prefix = [1] + [0] * len(nums)
        for i in range(1, len(prefix)):
            prefix[i] = prefix[i - 1] * nums[i - 1]
        suffix = [0] * len(nums) + [1]
        for j in range(len(suffix) - 2, -1, -1):
            suffix[j] = suffix[j + 1] * nums[j]
        return [prefix[i] * suffix[i + 1] for i in range(len(nums))]


solver = Solution()
print(solver.productExceptSelf([1, 2, 3, 4]))
