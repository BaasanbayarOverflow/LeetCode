class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def levelOrderBottom(root):
    stack = []
    def traverse(root, lvl):
        if root is None:
            return None 
        
        try:
            stack[lvl].append(root.val)
        except:
            stack.append([root.val])
        traverse(root.left, lvl + 1)
        traverse(root.right, lvl + 1)
        
    traverse(root, 0)
    return stack[::-1]


tree = TreeNode(3)
tree.left = TreeNode(9)
tree.right = TreeNode(20)
tree.right.left = TreeNode(15)
tree.right.right = TreeNode(7)

print(levelOrderBottom(tree))