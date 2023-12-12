import math 


def isPowerOfFour(n: int) -> bool:
    if (n < 0): return 0

    x = math.log(n, 4)
    return 1 if x - math.floor(x) == 0 else 0


print(isPowerOfFour(13))