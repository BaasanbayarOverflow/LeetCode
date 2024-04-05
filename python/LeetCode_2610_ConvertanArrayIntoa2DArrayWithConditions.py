def findMatrix(nums):
    hash = {}
    
    result = [[]]
    for n in nums:
        if (n in hash.keys()):
            inx = hash[n]
            try:
                result[inx].append(n)
            except:
                result.append([]) 
                result[inx].append(n)
            finally:
                hash[n] += 1
        else:
            hash[n] = 1
            result[0].append(n)

    return result


findMatrix([1,3,4,1,2,3,1])