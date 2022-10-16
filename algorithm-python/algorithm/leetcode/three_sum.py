class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        res: list[list[int]] = []
        memo: set[int] = set()
        for n in nums:
            for m in memo:
                if m < n:
                    s = m - n
                    if s in memo:
                        res.append([n, m, s])
            memo.add(n)
        return res
