class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def recoverTree(root):
    nodes = []
    
    def traverse(root):
        if root is None:
            return None 
        
        nodes.append(root)
        traverse(root.left)
        traverse(root.right)

    traverse(root) 
    vals = sorted(node.val for node in nodes)
    for i in range(len(vals)):
        nodes[i].val = vals[i]


tree = TreeNode(1)
tree.left = TreeNode(3)
tree.left.right = TreeNode(2)

recoverTree(tree)