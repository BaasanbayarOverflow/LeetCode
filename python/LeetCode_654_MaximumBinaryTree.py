from typing import List
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        self.tree = None
        def traverse(nlist, side, tmp):
            if not nlist:
                return
            
            low, high = 0, len(nlist) - 1
            inx = nlist.index(max(nlist))

            if side == '':
                self.tree = TreeNode(nlist[inx])
                tmp = self.tree
            elif side == 'left':
                tmp.left = TreeNode(nlist[inx])
                tmp = tmp.left
            elif side == 'right':
                tmp.right = TreeNode(nlist[inx])
                tmp = tmp.right

            if (inx != low):
                traverse(nlist[low:inx], 'left', tmp)

            if (inx != high):
                traverse(nlist[inx + 1 : high + 1], 'right', tmp)

        traverse(nums[0: len(nums)], '', None)
        return self.tree