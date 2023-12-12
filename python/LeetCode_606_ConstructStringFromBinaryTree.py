class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# Recursive
def traverseTree(root, word):
    if (root == None): return 

    word.append(str(root.val))

    if (root.left != None or root.right != None):
        word.append('(')
        traverseTree(root.left, word)
        word.append(')')

    if (root.right != None):
        word.append('(')
        traverseTree(root.right, word)
        word.append(')')


# Iterative
def tree2str(root) -> str:
    if (root == None):
        return ''

    stack = [root]
    tmp = []

    result = ''
    while stack:
        curr = stack[-1]

        if curr in tmp:
            stack.pop()
            result += ')'
        else:
            tmp.append(curr)
            result += f'({curr.val}'

            if curr.left == None and curr.right:
                result += '()'
            
            if curr.right != None:
                stack.append(curr.right)
            
            if curr.left != None:
                stack.append(curr.left)

    return result[1:-1]
    

tree = TreeNode(1)
tree.left = TreeNode(2)
tree.right = TreeNode(3)
tree.left.left = TreeNode(4)

print(tree2str(tree))