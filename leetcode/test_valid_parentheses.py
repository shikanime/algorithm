from collections import deque


class Solution:
    def isValid(self, s: str) -> bool:
        stack: deque[str] = deque()
        for c in s:
            if c == "{":
                stack.append("}")
            elif c == "[":
                stack.append("]")
            elif c == "(":
                stack.append(")")
            elif len(stack) == 0 or c != stack.pop():
                return False
        return len(stack) == 0


def test_solution():
    solver = Solution()
    assert solver.isValid("()") == True
    assert solver.isValid("()[]{}") == True
