from .valid_parentheses import Solution


def test_solution():
    solver = Solution()
    assert solver.isValid("()") == True
    assert solver.isValid("()[]{}") == True
