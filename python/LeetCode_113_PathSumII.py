class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def hasPathSum(root, targetSum):
    paths = []
    def traverse(root, path, sum):
        if root is None:
            return None 
        
        sum += root.val
        tmp = path + [root.val]
        if root.left is None and root.right is None and sum == targetSum:
            paths.append(tmp)

        traverse(root.left, tmp, sum)
        traverse(root.right, tmp, sum)
    
    traverse(root, [], 0)
    return paths


tree = TreeNode(1)
tree.left = TreeNode(2)
tree.right = TreeNode(3)

print(hasPathSum(tree, 3))