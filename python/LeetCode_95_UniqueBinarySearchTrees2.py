class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def generateTrees(n: int):
    def generate(left, right):
        if (left == right):
            return [TreeNode(left)]
        elif (left > right):
            return [None]
        
        result = []
        for val in range(left, right + 1):
            for l_branch in generate(left, val - 1):
                for r_branch in generate(val + 1, right): 
                    result.append(TreeNode(val, l_branch, r_branch))

        return result
    

    return generate(1, n)


print(generateTrees(3))