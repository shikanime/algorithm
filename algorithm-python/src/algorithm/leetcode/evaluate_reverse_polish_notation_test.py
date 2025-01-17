from .evaluate_reverse_polish_notation import Solution


def test_solution():
    solver = Solution()
    assert solver.evalRPN(["2", "1", "+", "3", "*"]) == 9
    assert solver.evalRPN(["4", "13", "5", "/", "+"]) == 6
    assert (
        solver.evalRPN(
            ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
        )
        == 22
    )
    assert solver.evalRPN(["4", "3", "-"]) == 1
