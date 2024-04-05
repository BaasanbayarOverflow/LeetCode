class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def insertIntoBST(root, val: int):
    if not root: return TreeNode(val)

    def traverse(root):
        if not root: return None

        if val < root.val:
            if not root.left and not root.right:
                root.left = TreeNode(val)
            else:
                root.left = traverse(root.left)
        else:
            if not root.left and not root.right:
                root.right = TreeNode(val)
            else:
                root.right = traverse(root.right)
        return root

    return traverse(root)


tree = TreeNode(4)
tree.left = TreeNode(2)
tree.right = TreeNode(7)
tree.left.left = TreeNode(1)
tree.left.right = TreeNode(3)

print(insertIntoBST(tree, 5))