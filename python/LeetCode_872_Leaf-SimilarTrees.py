def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
    r_1, r_2 = [], []
    def traverse(root, tmp):
        if not root:
            return
        elif not root.left and not root.right:
            tmp.append(root.val)
            return None

        traverse(root.left, tmp)
        traverse(root.right, tmp)

    traverse(root1, r_1)
    traverse(root2, r_2)
    return r_1 == r_2