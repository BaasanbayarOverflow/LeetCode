class Node:
    def __init__(self, val: int = 0, left = None, right = None, next = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


def connect(root):
    tmp = {}

    def conn(root, level):
        if root is None:
            return None
        
        level += 1
        conn(root.left, level)
        conn(root.right, level)
        
        if level in tmp:
            tmp[level].next = root
        tmp[level] = root
        
    tmp.clear()
    conn(root, 0)
    return root
        
