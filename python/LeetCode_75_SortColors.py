def sortColors(nums) -> None:
    low = 0
    high = len(nums) - 1

    inx = 0
    while (inx <= high):
        if (nums[inx] == 0):
            nums[low], nums[inx] = nums[inx], nums[low]
            low += 1

        elif (nums[inx] == 2):
            nums[high], nums[inx] = nums[inx], nums[high]
            high -= 1
            inx -= 1
        
        inx += 1


sortColors([1,2,0])
