# Optimal Solution
class NumArray:
    def __init__(self, nums):
        self.arr = []

        sum = 0
        for n in nums:
            sum += n
            self.arr.append(sum)

    def sumRange(self, left: int, right: int) -> int:
        if left == 0: 
            return self.arr[right]
        else:
            return self.arr[right] - self.arr[left - 1] 


nums = [-2, 0, 3, -5, 2, -1]
obj = NumArray(nums)
param_1 = obj.sumRange(0, 2)