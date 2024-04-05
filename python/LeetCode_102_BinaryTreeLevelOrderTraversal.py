class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def levelOrder(root):
    result = []
    def traverse(root, lvl):
        if root is None:
            return None 
        
        try:
            result[lvl].append(root.val)
        except:
            result.append([root.val])

        print(f"level - {lvl}, data - {root.val}")
        traverse(root.left, lvl + 1)
        traverse(root.right, lvl + 1)

    traverse(root, 0)

        

tree = TreeNode(3)
tree.left = TreeNode(9)
tree.right = TreeNode(20)
tree.right.left = TreeNode(15)
tree.right.right = TreeNode(7)

levelOrder(tree)