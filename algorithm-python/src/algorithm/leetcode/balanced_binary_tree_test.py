from .balanced_binary_tree import Solution, TreeNode


def test_solution():
    solver = Solution()
    assert (
        solver.isBalanced(
            TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
        )
        == True
    )
    assert (
        solver.isBalanced(
            TreeNode(
                1,
                TreeNode(2, TreeNode(3, TreeNode(4), TreeNode(4)), TreeNode(3)),
                TreeNode(2),
            )
        )
        == False
    )
    assert (
        solver.isBalanced(
            TreeNode(
                1,
                TreeNode(2, TreeNode(4, TreeNode(8)), TreeNode(5)),
                TreeNode(3, TreeNode(6)),
            )
        )
        == True
    )
    assert solver.isBalanced(TreeNode(1, None, TreeNode(2, None, TreeNode(3)))) == False
