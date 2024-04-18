class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        self.count = 0    
        def traverse(root, nums):
            if not root: 
                return None
            
            nums = max(nums, root.val)
            if root.val == nums:
                self.count += 1
                
            traverse(root.left, nums)
            traverse(root.right, nums)


        traverse(root, root.val)
        return self.count