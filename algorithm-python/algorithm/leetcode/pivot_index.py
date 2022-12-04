from itertools import accumulate

class Solution:
    def pivotIndex(self, nums: list[int]) -> int:
        for i, x in enumerate(accumulate(nums)):
            if x == sum(nums[i:]):
                return i
        return -1
