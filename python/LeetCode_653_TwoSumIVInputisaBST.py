class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def findTarget(root, k: int):
    tmp = dict()
    def traverse(root):
        nonlocal tmp        
        if not root: return None
        if k - root.val in tmp:
            return True
        tmp[root.val] = 0
        return traverse(root.left) or traverse(root.right)
    return traverse(root)


    
tree = TreeNode(5)
tree.left = TreeNode(3)
tree.right = TreeNode(6)
tree.left.left = TreeNode(2)
tree.left.right = TreeNode(4)
tree.right.right = TreeNode(7)

print(findTarget(tree, 5))
