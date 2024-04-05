class Solution:
    def findSecondMinimumValue(self, root: Optional[TreeNode]) -> int:
        self.m1 = self.m2 = 2147483648
        def traverse(root):
            if not root: return None

            if root.val <= self.m1:
                self.m1 = root.val
            elif root.val < self.m2:
                self.m2 = root.val
            traverse(root.left)
            traverse(root.right)

        traverse(root)
        return -1 if self.m2 >= 2147483648 else self.m2