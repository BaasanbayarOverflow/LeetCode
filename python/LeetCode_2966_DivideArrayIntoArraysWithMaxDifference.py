from math import ceil


def sort(nums):
    lngth = len(nums)
    if (lngth > 1):
        mid = lngth // 2

        l = nums[:mid]
        r = nums[mid:]
        sort(l)
        sort(r)

        i = j = k = 0
        while i < len(l) and j < len(r):
            if l[i] <= r[j]:
                nums[k] = l[i]
                i += 1
            else:
                nums[k] = r[j]
                j += 1
            k += 1

        while i < len(l):
            nums[k] = l[i]
            i += 1
            k += 1

        while j < len(r):
            nums[k] = r[j]
            j += 1
            k += 1


def divideArray(nums, k):
    if (not nums):
        return []

    # FASTER
    nums.sort()

    if (len(nums) % 3 != 0):
        return []

    result = []
    tmp = []
    for i in range(len(nums)):
        tmp.append(nums[i])
        
        if (i + 1) % 3 == 0:
            if (tmp[-1] - tmp[0] > k):
                return []
            
            result.append(tmp)
            tmp = []
    return result


divideArray([1,3,3,2,7,3], 3)