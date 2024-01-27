from .isomorphic_strings import Solution


def test_solution():
    solver = Solution()
    assert solver.isIsomorphic("egg", "add") == True
    assert solver.isIsomorphic("foo", "bar") == False
    assert solver.isIsomorphic("paper", "title") == True
    assert solver.isIsomorphic("badc", "baba") == False
    assert solver.isIsomorphic("bbbaaaba", "aaabbbba") == False
