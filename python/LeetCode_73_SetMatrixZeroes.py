def setZeroes(matrix) -> None:
    mem_i = set()
    mem_j = set()
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if (matrix[i][j] == 0):
                mem_j.add(j)
                mem_i.add(i)
    
    for i in range(len(matrix)):
        for j in mem_j:
            matrix[i][j] = 0

    for i in mem_i:
        for j in range(len(matrix[0])):
            matrix[i][j] = 0



setZeroes([[0,1,2,0],[3,4,5,2],[1,3,1,5]])