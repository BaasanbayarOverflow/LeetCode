class Solution:
    def missingNumber(self, nums) -> int:
      x = len(nums)
      return (x * (x + 1) // 2 - sum(nums))