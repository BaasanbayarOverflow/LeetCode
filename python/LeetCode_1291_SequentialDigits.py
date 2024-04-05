def getDigit(num):
    count = 0
    while (num > 0):
        num = num // 10
        count += 1
        
    return count


def sequentialDigits(low: int, high: int):
    seed = '123456789'
    limit = 10

    result = []

    mmin = getDigit(low)
    mmax = getDigit(high)
    tmp = mmin
    while (mmin <= tmp and mmax >= tmp):
        inx = tmp
        for i in range(limit - tmp):
            val = int(seed[i : inx])
            if (low <= val and val <= high):
                result.append(val)
            elif (val > high):
                break
            inx += 1

        tmp += 1
    return result
    

sequentialDigits(58, 155)