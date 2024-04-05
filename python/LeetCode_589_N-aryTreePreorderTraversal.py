class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        res = []
        def traverse(root):
            if root is None: return None
            res.append(root.val)
            for c in root.children:
                traverse(c)
        traverse(root)
        return res