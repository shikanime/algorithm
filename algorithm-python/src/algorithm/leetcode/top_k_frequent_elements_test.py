from .top_k_frequent_elements import Solution


def test_solution():
    solver = Solution()
    assert solver.topKFrequent([1, 1, 1, 2, 2, 3], 2) == [1, 2]
    assert solver.topKFrequent([-1, -1], 1) == [-1]
    assert solver.topKFrequent([1], 1) == [1]
    assert solver.topKFrequent([3, 0, 1, 0], 1) == [0]
