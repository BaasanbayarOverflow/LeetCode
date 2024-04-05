def largestDivisibleSubset(nums):
    nums.sort()
    lngth = len(nums)
    groups = [1] * lngth 
    inxs = [-1] * lngth

    minx = 0
    for i in range(lngth):
        for j in range(i):
            if nums[i] % nums[j] == 0:
                if groups[i] < 1 + groups[j]:
                    groups[i] = 1 + groups[j]
                    inxs[i] = j 
        if groups[i] > groups[minx]:
            minx = i 

    res = set()
    while minx != -1:
        res.add(nums[minx])
        minx = inxs[minx]
    return list(res)
     
     
largestDivisibleSubset([1,2,3])