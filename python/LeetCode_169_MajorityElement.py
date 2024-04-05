def majorityElement(nums) -> int:
    inx = 0
    counter = 0    
    for i in range(len(nums)):
        if nums[i] == nums[inx]:
            counter += 1
        else:
            counter -= 1

        if counter == 0:
            inx = i
            counter = 1

    return nums[inx]


print(majorityElement([2,1,2]))



"""

from collections import Counter

def majorityElement(nums) -> int:
    c = Counter(nums)
    mmax = 0
    res = 0 
    for key, val in c.items():
        if val > mmax:
            mmax = val 
            res = key
    
    return res


print(majorityElement([3,2,3]))

"""