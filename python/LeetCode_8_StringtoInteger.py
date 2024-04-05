def myAtoi(s: str) -> int:
    num = 0
    sign = 0
    is_negative = 0
    for letter in s:
        code = ord(letter)
        if (code >= 48 and code <= 57):
            num *= 10
            num += (code - 48)
            sign = 1
        elif (code == 45):
            if (sign): break
            sign = 1
            is_negative = 1
        elif (code == 43):
            if (sign): break
            sign = 1
        elif (code == 32):
            if (sign): break
            continue 
        else:
            break

    if (is_negative):
        num *= -1

    if (num <= -2147483648 or num >= 2147483647):
        return -2147483648 if is_negative else 2147483647
    return num


print(myAtoi("    -88827   5655  U"))