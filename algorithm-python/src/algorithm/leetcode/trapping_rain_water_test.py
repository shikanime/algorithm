from .trapping_rain_water import Solution


def test_solution():
    solver = Solution()
    assert solver.trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]) == 6
    assert solver.trap([4, 2, 0, 3, 2, 5]) == 9
