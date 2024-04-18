from typing import Optional
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        self.lvls = {}

        def traverse(root, lvl):
            if not root:
                return

            if lvl in self.lvls:
                self.lvls[lvl] = max(self.lvls[lvl], root.val)
            else:
                self.lvls[lvl] = max(-2147483649, root.val)

            traverse(root.left, lvl + 1)
            traverse(root.right, lvl + 1)
        
        traverse(root, 0)
        return list(self.lvls.values())