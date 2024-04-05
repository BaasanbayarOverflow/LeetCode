from math import inf

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def isValidBST(root) -> bool:
    def check(root, lower, higher):
        if (root is None):
            return True  
        
        if (lower >= root.val or root.val >= higher):
            return False

        return check(root.left, lower, root.val) and check(root.right, root.val, higher)

    return check(root, -inf, inf)

"""
tree = TreeNode(5)
tree.left = TreeNode(1)
tree.right = TreeNode(4)
tree.right.left = TreeNode(3)
tree.right.right = TreeNode(6)
"""

tree = TreeNode(2147483647)

print(isValidBST(tree))