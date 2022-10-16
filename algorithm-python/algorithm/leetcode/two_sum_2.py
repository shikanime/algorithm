class Solution:
    def twoSum(self, numbers: list[int], target: int) -> list[int]:
        front = 0
        back = len(numbers) - 1

        while front != back:
            curr = numbers[front] + numbers[back]
            if curr == target:
                return [front + 1, back + 1]
            if curr > target:
                back -= 1
            if curr < target:
                front += 1

        raise ValueError("No solution")
