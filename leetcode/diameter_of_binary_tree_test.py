from .diameter_of_binary_tree import TreeNode, Solution


def test_solution():
    solver = Solution()
    assert solver.diameterOfBinaryTree(TreeNode(1)) == 0
    assert solver.diameterOfBinaryTree(TreeNode(1, TreeNode(2))) == 1
    assert solver.diameterOfBinaryTree(TreeNode(1, TreeNode(2), TreeNode(3))) == 2
    assert (
        solver.diameterOfBinaryTree(
            TreeNode(1, TreeNode(2, TreeNode(4), TreeNode(5)), TreeNode(3))
        )
        == 3
    )
