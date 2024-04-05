from math import sqrt
from math import ceil

def isSquare(n):
    return int(sqrt(n)) ** 2 == n 

def numSquares(n: int) -> int:
    squares = [i ** 2 for i in range(1, ceil(sqrt(n)))]
    
    if isSquare(n):
        return 1
    
    colls = set()
    for num in squares:
        colls.add(n - num)
    
    res = 1
    while (colls):
        colls_2 = set()
        for num in colls:
            if isSquare(num):
                return res + 1
            for num_2 in squares:
                if num_2 > num:
                    break

                if num_2 not in colls_2:
                    colls_2.add(num - num_2)
        colls = colls_2
        res += 1
    
    return res


print(numSquares(12))