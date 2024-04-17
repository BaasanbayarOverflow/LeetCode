from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        self.path = 'zzzz'

        def traverse(root, path):
            if not root:
                return
            
            path += chr(root.val + 97)
            if not root.left and not root.right:
                self.path = min(self.path, path[::-1])

            traverse(root.left, path)
            traverse(root.right, path)
        
        traverse(root, '')
        return self.path