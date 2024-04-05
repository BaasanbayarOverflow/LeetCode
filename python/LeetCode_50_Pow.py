def myPow(x: float, n: int) -> float:
    is_negative = 1 if n < 0 else 0
    n = abs(n)

    res = 1
    while (n > 0):
        if n % 2 == 1:
            res *= x
        x *= x
        n //= 2

    return 1 / res if is_negative else res 
    

myPow(2., 10)