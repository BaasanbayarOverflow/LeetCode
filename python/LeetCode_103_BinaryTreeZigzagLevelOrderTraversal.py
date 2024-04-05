class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def zigzagLevelOrder(root):
    result = []
    def traverse(root, lvl):
        if root is None:
            return None

        try:
            if lvl & 1 == 1:
                result[lvl].insert(0, root.val)
            else:
                result[lvl].append(root.val)
        except: 
            result.append([root.val])

        traverse(root.left, lvl + 1)
        traverse(root.right, lvl + 1)

    traverse(root, 0)
    print(result)
    return result    


tree = TreeNode(3)
tree.left = TreeNode(9)
tree.right = TreeNode(20)
tree.right.left = TreeNode(15)
tree.right.right = TreeNode(7)

zigzagLevelOrder(tree)

