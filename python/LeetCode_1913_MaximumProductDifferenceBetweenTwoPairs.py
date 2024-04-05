def maxProductDifference(nums) -> int: 
    max_m = 0
    max_m_m = max_m 
    min_m = 10000
    min_m_m = min_m
    
    for n in nums:
        if n > max_m:
            max_m_m = max_m
            max_m = n         
        elif n > max_m_m or max_m == n:
            max_m_m = n

        if n < min_m:
            min_m_m = min_m 
            min_m = n
        elif n < min_m_m or n == min_m:
            min_m_m = n

    return (max_m * max_m_m) - (min_m * min_m_m)


print(maxProductDifference([4,2,5,9,7,4,8]))