def onesMinusZeros(grid):
    m = len(grid)
    n = len(grid[0])

    ones_row = [0] * m
    ones_col = [0] * n
    zeros_row = [0] * m
    zeros_col = [0] * n
    for i in range(m):
        for j in range(n):
            if (grid[i][j] == 0):
                zeros_row[i] += 1
                zeros_col[j] += 1
            elif (grid[i][j] == 1):
                ones_row[i] += 1
                ones_col[j] += 1
 
    diff = []
    for i in range(m):
        row = [0] * n
        for j in range(n):
            row[j] = ones_row[i] + ones_col[j] - zeros_row[i] - zeros_col[j]
        diff.append(row)


    return diff 

    
onesMinusZeros([[1,1,1],[1,1,1]])