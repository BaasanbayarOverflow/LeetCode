class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        result = [-1, -1]
        if len(nums) <= 0:
            return result
        
        inx = -1

        low = 0
        high = len(nums) - 1
        while (low <= high):
            mid = (low + high) // 2
            if (target == nums[mid]):
                inx = mid
                break
            elif (target > nums[mid]):
                low = mid + 1
            else:
                high = mid - 1

        if inx != -1:
            tmp = inx
            while (nums[tmp] == target):
                result[0] = tmp
                tmp -= 1
                if tmp < 0: break
            
            tmp = inx
            while (nums[tmp] == target):
                result[1] = tmp
                tmp += 1
                if tmp >= len(nums): break

        return result