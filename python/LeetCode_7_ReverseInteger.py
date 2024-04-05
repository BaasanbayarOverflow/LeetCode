def reverse(x: int) -> int:
    
    flag = 0
    if (x < 0):
        flag = 1
        x = abs(x) 
    
    rev = 0
    while (x != 0):
        rev *= 10
        rev += x % 10
        x //= 10
   
    if (rev <= -2147483648 or rev >= 2147483647):
        return 0

    return (rev * -1) if flag else rev 


reverse(-123)