from functools import reduce


class Solution:
    def maxArea(self, height: list[int]) -> int:
        def area(left: int, right: int):
            h = min(height[left], height[right])
            w = abs(right - left)
            return h * w

        def bestArea(edges: tuple[int, int], x: int):
            def followingBestArea(edges: tuple[int, int], lx: int):
                return (x, lx) if area(x, lx) > area(*edges) else edges

            return reduce(followingBestArea, reversed(range(x, len(height))), edges)

        return area(*reduce(bestArea, range(len(height)), (0, len(height) - 1)))
