def fourSum(nums, target: int):
    length = len(nums)
    if length < 4: return []

    result = []
    arr = sorted(nums)
    for i in range(length - 3):
        for j in range(i + 1, length - 2):  
            low = j + 1
            high = length - 1
            while (low < high):
                summ = arr[i] + arr[j] + arr[low] + arr[high]
                if (summ == target):
                    temp = [arr[i], arr[j], arr[low], arr[high]]
                    if (temp not in result):
                        result.append(temp)
                    high -= 1
                    low += 1
                elif (summ > target):
                    high -= 1
                elif (summ < target):
                    low += 1
            
    return result


print(fourSum([2, 2, 2, 2, 2], 8))