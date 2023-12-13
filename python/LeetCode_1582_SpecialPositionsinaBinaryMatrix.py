def numSpecial(mat) -> int:
    m = len(mat)
    n = len(mat[0])
    rows = [0 for i in range(m)]
    cols = [0 for i in range(n)]
    ones = []
    for i in range(m):
        for j in range(n):
            if mat[i][j] == 1:
                rows[i] += 1
                cols[j] += 1
                ones.append((i, j))
    
    res = 0
    for x in ones:
        i, j = x
        if rows[i] == 1 and cols[j] == 1:
            res += 1

    return res


numSpecial([[1,0,0],[0,0,1],[1,0,0]])


"""
def numSpecial(mat) -> int:
    m = len(mat)
    n = len(mat[0]) 
    total = 0
    for i in range(m):
        for j in range(n):
            if (mat[i][j] == 1):
                sum = 0
                for x in range(m):
                    sum += mat[x][j]
                
                for y in range(n):
                    sum += mat[i][y]

                if sum == 2:
                    total += 1
    return total       
"""


