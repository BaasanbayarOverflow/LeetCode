class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def minDiffInBST(root) -> int:
    mmin = 10000000
    mem = None
    def traverse(root):
        if not root: return None

        traverse(root.left)
        nonlocal mmin, mem
        if mem:
            mmin = min(mmin, root.val - mem.val)
        mem = root
        traverse(root.right)
    
    traverse(root)
    return mmin


tree = TreeNode(0)
tree.right = TreeNode(2236)
tree.right.left = TreeNode(1277)
tree.right.right = TreeNode(2776)
tree.right.left.left = TreeNode(519)

print(minDiffInBST(tree))
