# Optimal solution

"""
def maxProduct(self, nums: List[int]) -> int:
    largest, second_Largest = 0, 0

    for num in nums:
        if num > largest:
        second_Largest = largest
        largest = num
        else:
            second_Largest = max(second_Largest, num)
    return (largest-1) * (second_Largest-1)
"""


def maxProduct(nums) -> int:
    n = sorted(nums)
    return (n[-1] - 1) * (n[-2] - 1)


print(maxProduct([3,4,5,2]))