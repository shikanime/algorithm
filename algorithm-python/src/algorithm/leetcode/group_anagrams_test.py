from .group_anagrams import Solution


def test_solution():
    solver = Solution()
    assert solver.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]) == [
        ["eat", "tea", "ate"],
        ["tan", "nat"],
        ["bat"],
    ]
