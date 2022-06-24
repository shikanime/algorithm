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


solver = Solution()
print(solver.topKFrequent([1, 1, 1, 2, 2, 3], 2))
print(solver.topKFrequent([-1, -1], 1))
print(solver.topKFrequent([1], 1))
print(solver.topKFrequent([3, 0, 1, 0], 1))
