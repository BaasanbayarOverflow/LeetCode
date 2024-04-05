def divide(dividend: int, divisor: int) -> int:
    is_negative = 1 if (dividend > 0 and divisor < 0) or (dividend < 0 and divisor > 0) else 0
    dividend = abs(dividend)
    divisor = abs(divisor)

    result = 0
    while (dividend >= divisor):
        d = divisor
        mult = 1
        while (dividend >= d):
            dividend -= d 
            result += mult 
            mult += mult 
            d += d

    if (is_negative): result = -result
    return min(max(result, -2147483648), 2147483647)


divide(-2147483648, 1)
    
