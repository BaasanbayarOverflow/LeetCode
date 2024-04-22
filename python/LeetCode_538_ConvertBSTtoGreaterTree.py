from typing import Optional
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.summ = 0

        def traverse(root):
            if not root:
                return None

            traverse(root.right)
            self.summ += root.val
            root.val = self.summ
            traverse(root.left)

        traverse(root)
        return root