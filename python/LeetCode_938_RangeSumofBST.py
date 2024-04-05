class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def rangeSumBST(root, low: int, high: int) -> int:
    if root is None: return 0
    if root.val >= low and root.val <= high:
        return root.val + rangeSumBST(root.left, low, high) + rangeSumBST(root.right, low, high)
    elif root.val > high:
        return rangeSumBST(root.left, low, high)
    return rangeSumBST(root.right, low, high)

tree = TreeNode(1)
tree.left = TreeNode(2)
tree.left.right = TreeNode(3)
print(rangeSumBST(tree, 0, 145))