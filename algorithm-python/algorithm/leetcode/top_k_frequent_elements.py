import collections


class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        count: dict[int, int] = collections.defaultdict(int)
        for num in nums:
            count[num] += 1
        top: list[list[int]] = [[] for _ in range(0, len(nums))]
        for ck, cc in count.items():
            top[cc - 1].append(ck)
        res: list[int] = []
        for i in reversed(range(0, len(top))):
            for tk in top[i]:
                res.append(tk)
                if len(res) == k:
                    return res
        return []
