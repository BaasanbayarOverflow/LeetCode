class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def sumTree(root, s):
    if (root == None):
        return 0
    
    sumTree(root.left, s)
    if (root.left and root.left.left == None and root.left.right == None):
        s.append(root.left.val)
    
    sumTree(root.right, s)
    return 0


def sumOfLeftLeaves(root) -> int:
    if (root == None):
        return 0

    s = []
    sumTree(root, s)

    return sum(s) 



tree = TreeNode(3)
tree.left = TreeNode(9)
tree.right = TreeNode(20)
tree.left.left = TreeNode(15)
tree.left.right = TreeNode(7)

print(sumOfLeftLeaves(tree))



