# Optimal solution
def transpose(matrix):
    return zip(*matrix)

# Working solution
def transpose(matrix):
    column = len(matrix)
    row = len(matrix[0])
    T = []
    for j in range(row):
        tmp = []
        for i in range(column):
            tmp.append(matrix[i][j])
        T.append(tmp)
    return T


transpose([[1,2,3],[4,5,6],[7,8,9]])