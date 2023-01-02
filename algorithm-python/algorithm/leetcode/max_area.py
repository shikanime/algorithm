class Solution:
    def maxArea(self, height: list[int]) -> int:
        best_left, best_right = left, right = 0, len(height) - 1
        while left < right:
            if self.area(height, left, right) > self.area(
                height, best_left, best_right
            ):
                best_left, best_right = left, right
            if height[left] > height[right]:
                right -= 1
            else:
                left += 1

        return self.area(height, best_left, best_right)

    def area(self, height: list[int], left: int, right: int):
        h = min(height[left], height[right])
        w = right - left
        return h * w
