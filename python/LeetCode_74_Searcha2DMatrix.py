def searchMatrix(matrix, target: int) -> bool:
    len_m = len(matrix)
    len_n = len(matrix[0])
   
    
    inx = -1
    if (target >= matrix[0][0]):
        for i in range(len_m):
            if (matrix[i][len_n - 1] >= target):
                inx = i
                break 

    if inx == -1: return 0
    
    low = 0
    high = len_n - 1
    while (low <= high):
        mid = low + ((high - low) // 2)

        if (matrix[inx][mid] == target):
            return 1 
        elif (matrix[inx][mid] > target):
            high = mid - 1
        elif (matrix[inx][mid] < target):
            low = mid + 1


    return 0
    

    


searchMatrix([[1,3,5,7],[10,11,16,20],[23,30,34,60]], 13)