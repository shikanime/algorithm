from .best_time_to_buy_and_sell_stock import Solution


def test_solution():
    solver = Solution()
    assert solver.maxProfit([7, 1, 5, 3, 6, 4]) == 5
    assert solver.maxProfit([2, 4, 1]) == 2
