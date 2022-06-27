class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = "".join(c for c in s if c.isalnum()).lower()
        return s == s[::-1]


def test_solution():
    solver = Solution()
    assert solver.isPalindrome("A man, a plan, a canal: Panama") == True
