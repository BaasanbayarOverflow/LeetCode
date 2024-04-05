def guessNumber(self, n: int) -> int:
    low = 0
    high = n
    res = guess(n) 
    while (res != 0):
        mid = low + ((high - low) // 2)

        res = guess(mid)  
        if (res == 0):
            return mid
        elif (res == 1):
            low = mid
        elif (res == -1):
            high = mid

    return n