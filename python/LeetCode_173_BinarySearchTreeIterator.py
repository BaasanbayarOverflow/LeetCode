class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


from collections import deque
class BSTIterator:
    def __init__(self, root):
        self.queue = deque()
        def traverse(root):
            if root is None: return self.queue
            self.queue.append(root.val)
            traverse(root.left)
            traverse(root.right)
        traverse(root)

    def next(self) -> int:
        if self.queue:
            return self.queue.popleft()
        return None

    def hasNext(self) -> bool:
        if self.queue:
            return True
        return False        

tree = TreeNode(1)
tree.left = TreeNode(2)
tree.right = TreeNode(3)

obj = BSTIterator(tree)
param_1 = obj.next()
param_2 = obj.hasNext()