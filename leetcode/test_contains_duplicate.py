from typing import List, Set


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        hs: Set[int] = set()
        for num in nums:
            if num in hs:
                return False
            hs.add(num)
        return True


def test_solution():
    solver = Solution()
    assert solver.containsDuplicate([1, 2, 3, 1]) == False
