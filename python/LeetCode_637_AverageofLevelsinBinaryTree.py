class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


from collections import defaultdict
def averageOfLevels(root):
    ave = defaultdict(list)
    def traverse(root, lvl):
        if root is None: return None

        ave[lvl].append(root.val)
        traverse(root.left, lvl + 1)
        traverse(root.right, lvl + 1)
    traverse(root, 1)
    
    res = []
    for k, v in ave.items():
        res.append(sum(v) / len(v))
    return res


tree = TreeNode(3)
tree.left = TreeNode(9)
tree.right = TreeNode(20)
tree.right.left = TreeNode(15)
tree.right.right = TreeNode(7)
print(averageOfLevels(tree))