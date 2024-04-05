class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def getMinimumDifference(self, root) -> int:
        self.m = 100000000
        self.mem = None
        def traverse(root):
            if not root: return None

            traverse(root.left)
            if self.mem:
                self.m = min(self.m, abs(root.val - self.mem.val))
            self.mem = root
            traverse(root.right)
        traverse(root)
        return self.m