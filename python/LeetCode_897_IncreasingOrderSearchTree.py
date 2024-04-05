class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

        
class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        self.tree = self.tmp = None
        def traverse(root):
            if root is None: return None

            traverse(root.left)
            if self.tmp:
                self.tmp.right = root
            else:
                self.tree = root
            self.tmp = root
            root.left = None
            traverse(root.right)  
        traverse(root)
        return self.tree
    

tree = TreeNode(5)
tree.left = TreeNode(1)
tree.right = TreeNode(7)
print(increasingBST(tree))