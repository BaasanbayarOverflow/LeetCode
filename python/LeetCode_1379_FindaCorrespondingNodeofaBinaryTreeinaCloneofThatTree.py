# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        self.tmp = None
        def traverse(root):
            if not root: return None

            if root.val == target.val:
                self.tmp = root
            traverse(root.left)
            traverse(root.right)

        traverse(cloned)
        return self.tmp