from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.counter = 0
        self.nums = []

        def traverse(root):
            if not root:
                return None
            
            traverse(root.left)
            if (self.counter >= k):
                return
            
            self.nums.append(root.val)
            self.counter += 1
            traverse(root.right)
        
        traverse(root)
        self.nums.sort()
        return self.nums[k - 1]