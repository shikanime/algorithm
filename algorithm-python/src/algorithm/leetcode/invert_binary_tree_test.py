from .invert_binary_tree import Solution, TreeNode


def test_solution():
    solver = Solution()
    assert solver.invertTree(TreeNode(2, TreeNode(1), TreeNode(3)))
