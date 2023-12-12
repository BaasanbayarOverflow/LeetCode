class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def binaryTreePaths(root):
    if (root == None): return [""]
    
    path = []
    stack = []
    curr = root
    prev = None
 
    result = []
    while curr or stack:
        while curr:
            stack.append(curr)
            path.append(curr.val)
            curr = curr.left
 
        curr = stack[-1]
 
        if curr.right and curr.right != prev:
            curr = curr.right
        else:
            if not curr.right and not curr.left:
                result.append( "->".join(map(str, path)))
 
            stack.pop()
            path.pop()
            prev = curr
            curr = None
    
    return result

