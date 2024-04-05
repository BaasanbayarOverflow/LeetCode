def imageSmoother(img):
    x = len(img)
    y = len(img[0])

    result = [] 
    for i in range(x):
        row = [0] * y
        for j in range(y):  
            top = max(0, i - 1)
            bottom = min(x, i + 2)
            left = max(0, j - 1) 
            right = min(y, j + 2)
            
            div = 0
            summ = 0
            for k in range(top, bottom):
                for z in range(left, right):
                    summ += img[k][z]
                    div += 1
                    
            row[j] = (summ // div)
        result.append(row)

    return result


imageSmoother([[100,200,100],[200,50,200],[100,200,100]])