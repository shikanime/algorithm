from itertools import accumulate


class Solution:
    def pivotIndex(self, nums: list[int]) -> int:
        right = sum(nums)
        for i, (v, left) in enumerate(zip(nums, accumulate(nums, initial=0))):
            if left == right - left - v:
                return i
        return -1
