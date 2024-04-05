from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def delNodes(self, root, to_delete):
        self.mem = deque()
        def traverse(root):
            if not root:
                return
            
            traverse(root.left)
            traverse(root.right)

            if root.val in to_delete:
                if root.left and root.left.val not in to_delete: 
                    self.mem.append(root.left)
                if root.right and root.right.val not in to_delete: 
                    self.mem.append(root.right)
            
            if root.left and root.left.val in to_delete:
                root.left = None
            if root.right and root.right.val in to_delete:
                root.right = None

        traverse(root)
        if root.val not in to_delete:
            self.mem.appendleft(root)
        return self.mem