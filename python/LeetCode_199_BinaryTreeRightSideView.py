class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def rightSideView(root):
    res = []
    def traverse(root, lvl):
        if root is None:
            return None
        
        try:
            res[lvl] = root.val
        except:
            res.append(root.val)

        lvl += 1
        traverse(root.left, lvl)
        traverse(root.right, lvl)

    traverse(root, 0)
    return res


tree = TreeNode(1)
tree.left = TreeNode(2)
tree.left.right = TreeNode(3)
print(rightSideView(tree))