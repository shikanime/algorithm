class Solution:
    def search(self, nums: list[int], target: int) -> int:
        if len(nums) != 0:
            idx = int(len(nums) / 2)
            if nums[idx] == target:
                return idx
            elif nums[idx] < target:
                return self.search(nums[idx:], target) + idx
            elif nums[idx] > target:
                return self.search(nums[:idx], target) + idx
        return -1
