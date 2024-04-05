class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def sumNumbers(root) -> int:
    paths = []
    def traverse(root, num):
        if (root is None):
            return None

        num += str(root.val)
        if root.left is None and root.right is None:
            paths.append(int(num))
        
        traverse(root.left, num)
        traverse(root.right, num)

    traverse(root, '')
    return sum(paths)

tree = TreeNode(1)
tree.left = TreeNode(2)
tree.right = TreeNode(3)
print(sumNumbers(tree))