class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def sumRootToLeaf(root) -> int:
    total = 0
    def traverse(root, bin):
        if root is None:
            return 0
        
        bin = (bin << 1) + root.val
        if root.left is None and root.right is None:
            nonlocal total
            total += bin
        
        traverse(root.left, bin)
        traverse(root.right, bin)
    
    traverse(root, 0)
    return total


tree = TreeNode(1)
tree.left = TreeNode(0)
tree.left.left = TreeNode(0)
tree.left.right = TreeNode(1)
tree.right = TreeNode(1)
tree.right.left = TreeNode(0)
tree.right.right = TreeNode(1)
print(sumRootToLeaf(tree))