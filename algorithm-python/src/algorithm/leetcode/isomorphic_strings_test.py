from .isomorphic_strings import Solution


def test_solution():
    solver = Solution()
    assert solver.isIsomorphic("egg", "add")
    assert not solver.isIsomorphic("foo", "bar")
    assert solver.isIsomorphic("paper", "title")
    assert not solver.isIsomorphic("badc", "baba")
    assert not solver.isIsomorphic("bbbaaaba", "aaabbbba")
