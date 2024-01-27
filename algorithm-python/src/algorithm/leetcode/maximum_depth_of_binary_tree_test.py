from .maximum_depth_of_binary_tree import Solution, TreeNode


def test_solution():
    solver = Solution()
    assert (
        solver.maxDepth(
            TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
        )
        == 3
    )
