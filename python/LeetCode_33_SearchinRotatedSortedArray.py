def search(nums, target: int) -> int:
    low = 0 
    high = len(nums) - 1
    while (low <= high):
        if (nums[low] == target):
            return low 
        elif (nums[high] == target):
            return high 
        low += 1
        high -= 1

    return -1 


print(search([4,5,6,7,0,1,2], 3))