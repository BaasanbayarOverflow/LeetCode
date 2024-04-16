from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        def traverse(root_1, root_2, checking=False):
            if root_1 is None or root_2 is None:
                return root_1 is root_2  
            if root_1.val == root_2.val: 
                if traverse(root_1.left, root_2.left, True) and traverse(root_1.right, root_2.right, True):
                    return True
            return not checking and traverse(root_1.left, root_2) or traverse(root_1.right, root_2)
 
        return traverse(root, subRoot)