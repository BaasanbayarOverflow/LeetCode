def intersect(nums1, nums2):
    hash = {}
    for n in nums1:
        if (n not in hash):
            hash[n] = 0
    
    for n in nums2:
        if (n in hash):
            hash[n] += 1

    res = []
    for k, v in hash.items():
        if (v > 0):
            ...
        
    return res


print(intersect([4,9,5], [9,4,9,8,4]))