def isPerfectSquare(num: int) -> bool:
    low = 0 
    high = num 
    while (low < high - 1):
        mid = low + ((high - low) // 2)
        
        if (mid ** 2 == num):
            return 1
        
        if (mid ** 2 > num):
            high = mid 
        elif (mid ** 2 < num):
            low = mid 

    return 0 


print(isPerfectSquare(169))