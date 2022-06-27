class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        hs: set[int] = set()
        for num in nums:
            if num in hs:
                return False
            hs.add(num)
        return True
