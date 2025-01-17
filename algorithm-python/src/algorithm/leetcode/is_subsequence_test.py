from .is_subsequence import Solution


def test_solution():
    solver = Solution()
    assert solver.isSubsequence("abc", "ahbgdc") == True
    assert solver.isSubsequence("axc", "ahbgdc") == False
    assert solver.isSubsequence("b", "abc") == True
