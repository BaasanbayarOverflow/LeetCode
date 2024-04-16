class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        self.ans = 0
        def traverse(root, c):
            if not root: return 0, 0

            left, c_1 = traverse(root.left, c)
            right, c_2 = traverse(root.right, c)
            c = c_1 + c_2 + c

            summ = root.val + left + right
            ave = summ // c
            if root.val == ave:
                self.ans += 1
            return summ, c
        
        traverse(root, 1)
        return self.ans