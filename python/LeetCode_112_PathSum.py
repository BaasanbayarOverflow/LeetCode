class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def hasPathSum(root, targetSum):
    def traverse(root, summ):
        if root is None:
            return True
        
        summ += root.val
        if root.left is None and root.right is None:
            return False if targetSum == summ else True
        return traverse(root.left, summ) and traverse(root.right, summ)

    return not traverse(root, 0)


tree = TreeNode(1)
tree.left = TreeNode(2)
tree.right = TreeNode(3)

print(hasPathSum(tree, 2))