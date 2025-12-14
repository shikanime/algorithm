from .is_subsequence import Solution


def test_solution():
    solver = Solution()
    assert solver.isSubsequence("abc", "ahbgdc")
    assert not solver.isSubsequence("axc", "ahbgdc")
    assert solver.isSubsequence("b", "abc")
