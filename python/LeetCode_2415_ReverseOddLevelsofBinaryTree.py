class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def reverseOddLevels(root):
    def traverse(left, right, lvl):
        if not left and not right:
            return

        if lvl % 2 == 0:
            left.val, right.val = right.val, left.val
        traverse(left.left, right.right, lvl + 1)
        traverse(left.right, right.left, lvl + 1)

    traverse(root.left, root.right, 0)
    return root


tree = TreeNode(4)
tree.left = TreeNode(2)
tree.right = TreeNode(7)

print(reverseOddLevels(tree))