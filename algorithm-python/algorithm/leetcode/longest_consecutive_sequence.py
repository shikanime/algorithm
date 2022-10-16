from functools import reduce, partial


class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        def searchGlobalLongestConsecutive(nums: set[int], best: int, curr: int) -> int:
            local_best = searchLocalLongestConsecutive(nums, curr)
            return local_best if local_best > best else best

        def searchLocalLongestConsecutive(nums: set[int], curr: int) -> int:
            return (
                searchLocalLongestConsecutive(nums, curr + 1) + 1 if curr in nums else 0
            )

        return reduce(
            partial(searchGlobalLongestConsecutive, set(nums)),
            filter(lambda x: x - 1 not in nums, nums),
            0,
        )
