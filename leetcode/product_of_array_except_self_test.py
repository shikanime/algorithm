from .product_of_array_except_self import Solution


def test_solution():
    solver = Solution()
    assert solver.productExceptSelf([1, 2, 3, 4]) == [24, 12, 8, 6]
