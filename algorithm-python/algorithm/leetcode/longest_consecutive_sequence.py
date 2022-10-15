from functools import reduce


class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        nseq = [False] * abs(min(nums, default=0) - 1)
        pseq = [False] * (max(nums, default=0) + 1)
        for n in nums:
            if n >= 0:
                pseq[n] = True
            else:
                nseq[n] = True

        def seqlen(acc: list[int], n: int):
            if n:
                acc[-1] += 1
            else:
                acc.append(0)
            return acc

        return max(reduce(seqlen, nseq + pseq, [0]))
