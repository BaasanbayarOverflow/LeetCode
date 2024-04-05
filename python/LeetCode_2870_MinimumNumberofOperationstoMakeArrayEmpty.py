from collections import Counter


def minOperations(nums) -> int:
    hash = Counter(nums)
    
    """
    for n in nums:
        if n in hash.keys():
            hash[n] += 1
        else:
            hash[n] = 1
    """

    techs = 0
    for k, v in hash.items():
        if (v % 3 == 0):
            techs += v // 3
            continue
        else:
            while (v != 0):
                if (v == 1):
                    return -1
                
                v -= 2
                techs += 1
               
                if (v % 3 == 0):
                    techs += v // 3 
                    v = 0
        
    return techs


print(minOperations([2,1,2,2,3,3]))