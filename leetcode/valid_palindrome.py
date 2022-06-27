class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = "".join(c for c in s if c.isalnum()).lower()
        return s == s[::-1]


solver = Solution()
print(solver.isPalindrome("A man, a plan, a canal: Panama"))
