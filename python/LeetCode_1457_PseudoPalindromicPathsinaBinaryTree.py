from collections import Counter
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def pseudoPalindromicPaths (self, root: Optional[TreeNode]) -> int:
        self.result = 0
        
        def traverse(root, path):
            if not root:
                return
            
            path += str(root.val)
            if not root.left and not root.right:
                c = Counter(list(path))
                flag = 1
                tmp = 1
                for value in c.values():
                    if value % 2 and flag:
                        flag = 0
                    elif value % 2:
                        tmp = 0

                if not flag and tmp:
                    self.result += 1            


            traverse(root.left, path)
            traverse(root.right, path)

        traverse(root, '')
        return self.result