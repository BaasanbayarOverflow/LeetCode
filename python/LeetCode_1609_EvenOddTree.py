class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isEvenOddTree(self, root) -> bool:
        self.tmp = []
        def traverse(root, lvl):
            if not root: return True

            if lvl % 2 == 0:
                if len(self.tmp) - 1 < lvl:
                    self.tmp.append(-10000)

                if root.val % 2 == 0 or self.tmp[lvl] >= root.val:
                    self.tmp[lvl] = root.val
                    return False
                self.tmp[lvl] = root.val
            else:
                if len(self.tmp) - 1 < lvl:
                    self.tmp.append(10000)

                if root.val % 2 == 1 or self.tmp[lvl] <= root.val:
                    self.tmp[lvl] = root.val
                    return False
                self.tmp[lvl] = root.val
        
            return traverse(root.left, lvl + 1) and traverse(root.right, lvl + 1)
        
        return traverse(root, 0)
    
    

tree = TreeNode(1)
tree.left = TreeNode(10)
tree.right = TreeNode(4)
tree.left.left = TreeNode(3)
tree.right.left = TreeNode(7)
tree.right.right = TreeNode(9)

s = Solution()
print(s.isEvenOddTree(tree))