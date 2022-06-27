import collections


class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        groups: dict[int, list[str]] = collections.defaultdict(list)
        for s in strs:
            groups[hash(str(sorted(s)))].append(s)
        return list(groups.values())


def test_solution():
    solver = Solution()
    assert solver.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]) == [
        ["eat", "tea", "ate"],
        ["tan", "nat"],
        ["bat"],
    ]
