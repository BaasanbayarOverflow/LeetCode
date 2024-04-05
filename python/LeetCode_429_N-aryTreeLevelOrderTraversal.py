from collections import defaultdict

class Solution:
    def levelOrder(self, root):
        self.mem = defaultdict(list)
        def traverse(root, lvl):
            if not root:
                return None

            self.mem[lvl].append(root.val)
            for child in root.children:
                traverse(child, lvl + 1)
        
        traverse(root, 0)
        result = []
        for i in range(len(self.mem)):
            result.append(self.mem[i])
        return result
    

"""
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        self.mem = []
        def traverse(root, lvl):
            if not root:
                return None

            try:
                self.mem[lvl].append(root.val)
            except:
                self.mem.append([root.val])
            for child in root.children:
                traverse(child, lvl + 1)
        
        traverse(root, 0)
        return self.mem
"""