class Solution:
    def search(self, nums: list[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        while left <= right:
            middle = left + ((right - left) // 2)
            if target > nums[middle]:
                left += 1
            elif nums[middle] > target:
                right -= 1
            else:
                return middle
        return -1
