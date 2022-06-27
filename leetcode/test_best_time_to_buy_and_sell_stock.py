class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        buy = prices[0]
        profit = 0
        for price in prices[1:]:
            if buy > price:
                buy = price
            profit = max(profit, price - buy)
        return profit


def test_solution():
    solver = Solution()
    assert solver.maxProfit([7, 1, 5, 3, 6, 4]) == 5
    assert solver.maxProfit([2, 4, 1]) == 2
