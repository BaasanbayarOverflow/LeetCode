class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def searchBST(root, val: int):
    if root is None: return None

    curr = root
    while curr:
        if curr.val > val:
            curr = curr.left
        elif curr.val < val:
            curr = curr.right
        else:
            return curr
    return None


tree = TreeNode(4)
tree.left = TreeNode(2)
tree.right = TreeNode(7)
tree.left.left = TreeNode(1)
tree.left.right = TreeNode(3)
print(searchBST(tree, 2))