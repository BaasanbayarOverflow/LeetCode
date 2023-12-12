def getRow(rowIndex: int):
    arr = [1]
    for i in range(rowIndex + 1):
        for j in range(1, i + 1):
            if (j == i):
                arr.insert(0, 1)  
            else:
                arr[j - 1] = arr[j - 1] + arr[j]

    return arr

getRow(5)



# 0(N)
"""
def getRow(rowIndex: int):
    res = [1]
    prev = 1
    for k in range(1, rowIndex + 1):
        next_val = prev * (rowIndex - k + 1) // k
        res.append(next_val)
        prev = next_val
    return res
"""