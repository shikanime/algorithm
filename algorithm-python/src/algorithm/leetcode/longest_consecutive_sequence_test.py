from .longest_consecutive_sequence import Solution


def test_solution():
    solver = Solution()
    assert solver.longestConsecutive([100, 4, 200, 1, 3, 2]) == 4
    assert solver.longestConsecutive([0, -1]) == 2
    assert (
        solver.longestConsecutive(
            [4, 0, -4, -2, 2, 5, 2, 0, -8, -8, -8, -8, -1, 7, 4, 5, 5, -4, 6, 6, -3]
        )
        == 5
    )
