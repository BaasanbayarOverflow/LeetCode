class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def findTilt(root) -> int:
    summ = 0
    def traverse(root):
        nonlocal summ
        if not root: 
            return 0
        
        left = traverse(root.left)
        right = traverse(root.right)
        summ += abs(left - right)
        return root.val + left + right
    
    traverse(root)
    return summ