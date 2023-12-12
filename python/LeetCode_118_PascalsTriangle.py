def generate(numRows: int):
    arr = []
    for i in range(numRows):
        tmp = []
        for j in range(i + 1):
            if (j == 0 or j == i):
                tmp.append(1)
            else:
                tmp.append(arr[i - 1][j - 1] + arr[i - 1][j])
        arr.append(tmp)

    return arr


generate(5)