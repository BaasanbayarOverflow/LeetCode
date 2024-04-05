def findBottomLeftValue(root) -> int:
    res = []
    def traverse(root, lvl):
        if root is None: return None

        if lvl >= len(res):
            res.append(root.val)

        traverse(root.left, lvl + 1)
        traverse(root.right, lvl + 1)
    
    traverse(root, 0)
    return res[-1]