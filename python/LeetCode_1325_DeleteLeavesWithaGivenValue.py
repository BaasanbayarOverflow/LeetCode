class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def removeLeafNodes(self, root, target: int):
        # direction LEFT  - 0
        # direction RIGHT - 1
        def traverse(root, parent, direction):
            if not root: return None

            traverse(root.left, root, 0)
            traverse(root.right, root, 1)
            if not root.left and not root.right:
                if root.val == target:
                    if direction == 0: parent.left = None
                    elif direction == 1: parent.right = None 


        traverse(root, None, -1)
        if not root.left and not root.right and root.val == target: return None
        return root