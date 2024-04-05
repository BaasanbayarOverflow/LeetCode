def rotate(matrix) -> None:
    lngth = len(matrix)
    for i in range(lngth):
        for j in range(i + 1, lngth):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]


    hlf = (lngth // 2)
    for i in range(lngth):
        inx = lngth - 1
        for j in range(hlf):
            matrix[i][j], matrix[i][inx] = matrix[i][inx], matrix[i][j]
            inx -= 1


     



rotate([[1,2,3],[4,5,6],[7,8,9]])