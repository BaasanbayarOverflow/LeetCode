# Optimal Solution
def findSpecialInteger(arr) -> int:
    maxPercent = len(arr)/4 
    for num in arr:
        if arr.count(num) > maxPercent:
            return num


def findSpecialInteger(arr) -> int: 
    counter = {}
    for n in arr:
        if n in counter:
            counter[n] += 1
        else:
            counter[n] = 1

    max = -1
    result = 0
    for k, v in counter.items():
        frequency = v / len(arr) > 0.25
        if (v > max and frequency):
            max = v 
            result = k
    return result


findSpecialInteger([1,2,2,6,6,6,6,7,10])