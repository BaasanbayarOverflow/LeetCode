def largestPerimeter(nums) -> int:
    lngth = len(nums)
    if lngth < 3:
        return -1 
    
    nums.sort()
    summ = sum(nums)

    for i in range(lngth - 1, -1, -1):
        if i == 1: break
        if (nums[i] < summ - nums[i]):
            return summ
        summ -= nums[i]

    return -1


print(largestPerimeter([1,12,1,2,5,50,3]))