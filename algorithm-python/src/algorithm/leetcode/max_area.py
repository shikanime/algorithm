class Solution:
    def maxArea(self, height: list[int]) -> int:
        best, left, right = 0, 0, len(height) - 1
        while left < right:
            area = min(height[right], height[left]) * (right - left)
            if height[left] > height[right]:
                right -= 1
            else:
                left += 1
            best = max(best, area)
        return best
