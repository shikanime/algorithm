from functools import reduce


class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        remaining = reduce(
            lambda acc, x: acc[1:] if x == next(iter(acc), None) else acc,
            list(t),
            list(s),
        )
        return len(remaining) == 0
