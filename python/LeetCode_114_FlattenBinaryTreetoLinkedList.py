class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def flatten(root):
    if root is None:
        return 
    
    stack = [root]
    while stack:
        curr = stack.pop()

        if curr.right:
            stack.append(curr.right)
        if curr.left:
            stack.append(curr.left)
        
        if stack:
            curr.right = stack[-1]
        curr.left = None


tree = TreeNode(1)
tree.left = TreeNode(2)
tree.left.left = TreeNode(3)
tree.left.right = TreeNode(4)
tree.right = TreeNode(5)
tree.right.right = TreeNode(6)
flatten(tree)


"""
def flattenTree(root, mem):
    curr = root
    for i in range(1, len(mem)):
        curr.right = TreeNode(mem[i])
        curr = curr.right
    return curr


def flatten(root):
    if root is None:
        return

    mem = []
    def traverse(root):
        if root is None:
            return None 
        
        mem.append(root.val)
        traverse(root.left)
        traverse(root.right)
    
    traverse(root)
    root.left = root.right = None
    root = flattenTree(root, mem)
    return
"""