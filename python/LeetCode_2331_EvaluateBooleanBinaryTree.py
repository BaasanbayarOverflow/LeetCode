class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        

def evaluateTree(root) -> bool:
    def traverse(root):
        if not root.left and not root.right: return root.val
        if root.val == 2:
            return traverse(root.left) or traverse(root.right)
        elif root.val == 3:
            return traverse(root.left) and traverse(root.right)

    return traverse(root)
    

tree = TreeNode(2)
tree.left = TreeNode(1)
tree.right = TreeNode(3)
tree.right.left = TreeNode(0)
tree.right.right = TreeNode(1)
print(evaluateTree(tree))