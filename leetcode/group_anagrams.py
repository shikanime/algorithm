import collections


class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        map: dict[int, list[str]] = collections.defaultdict(list)
        for s in strs:
            map[hash(str(sorted(s)))].append(s)
        return list(map.values())


solver = Solution()
print(solver.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))
