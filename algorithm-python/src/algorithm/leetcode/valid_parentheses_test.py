from .valid_parentheses import Solution


def test_solution():
    solver = Solution()
    assert solver.isValid("()")
    assert solver.isValid("()[]{}")
