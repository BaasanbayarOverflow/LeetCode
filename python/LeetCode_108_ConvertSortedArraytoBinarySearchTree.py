class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def sortedArrayToBST(nums):
    def create(nums):
        if not nums:
            return None
        
        lngth = len(nums)
        mid = lngth - (lngth // 2) if lngth % 2 == 0 else lngth // 2
        tree = TreeNode(nums[mid])

        tree.left = create(nums[0:mid])
        tree.right = create(nums[mid+1:lngth])
        return tree

    tree = create(nums)
    return tree

print(sortedArrayToBST([-10,-3,0,5,9,10]))