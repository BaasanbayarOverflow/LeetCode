def traverse(root, arr):
    if root == None:
        return 

    traverse(root.left, arr)
    arr.append(root.val)
    traverse(root.right, arr)
    
# Recursive approach     
def inorderTraversal(root):
    arr = []
    traverse(root, arr)
    return arr


# Iterative approach 
def inorderTraversalIterate(root):
    if (root == None):
        return 
    

    arr = []
    stack = []
    curr = root 

    while (stack or curr):
        while (curr):
            stack.append(curr)
            curr = curr.left

        curr = stack.pop()
        arr.append(curr.val)
        curr = curr.right

    return arr


inorderTraversal()
inorderTraversalIterate()