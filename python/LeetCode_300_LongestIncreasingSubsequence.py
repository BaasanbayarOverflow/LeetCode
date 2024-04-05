def lengthOfLIS(nums) -> int:
    length = len(nums)
    if (length == 0):
        return 0

    result = [nums[0]]
    for i in range(length):
        if (nums[i] > result[-1]):
            result.append(nums[i])
        else:
            low = 0 
            high = len(result) - 1
            while (low < high):
                mid = low + ((high - low) // 2)
                if (result[mid] < nums[i]):
                    low = mid + 1
                else:
                    high = mid

            result[low] = nums[i]

    return len(result)


lengthOfLIS([10,9,2,5,3,7,101,18])