from .valid_palindrome import Solution


def test_solution():
    solver = Solution()
    assert solver.isPalindrome("A man, a plan, a canal: Panama") == True
