from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        def traverse(root, lvl, left, past):
            if not root and lvl == depth:
                if left:
                    past.left = TreeNode(val)
                else:
                    past.right = TreeNode(val)
            
            if not root: return

            traverse(root.left, lvl + 1, True, root)
            traverse(root.right, lvl + 1, False, root)

            if lvl == depth:
                tmp = TreeNode(val)
                if past and left:
                    past.left = tmp
                elif past and not left:
                    past.right = tmp
                
                if left:
                    tmp.left = root
                else:
                    tmp.right = root


        if depth == 1:
            return TreeNode(val, left=root)
        else:
            traverse(root, 1, True, None)
        return root