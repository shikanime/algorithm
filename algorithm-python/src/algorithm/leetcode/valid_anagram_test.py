from .valid_anagram import Solution


def test_solution():
    solver = Solution()
    assert solver.isAnagram("anagram", "nagaram") == True
