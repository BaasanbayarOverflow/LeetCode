class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def mergeTrees(root1, root2):
    if root1 is None and root2 is None:
        return None
    
    if root1 and root2:
        tree = TreeNode(root1.val + root2.val)
        tree.left = mergeTrees(root1.left, root2.left)
        tree.right = mergeTrees(root1.right, root2.right)
        return tree
    elif root1 is None:
        return root2
    elif root2 is None:
        return root1
    return None


tree = TreeNode(1)
tree.left = TreeNode(3)
tree.right = TreeNode(2)
tree.left.left = TreeNode(5)

t = TreeNode(2)
t.left = TreeNode(1)
t.right = TreeNode(3)
t.left.right = TreeNode(4)
t.right.right = TreeNode(7)
print(mergeTrees(tree, t))