def toHex(num: int) -> str:
    if (num == 0):
        return '0'
    elif (num < 0):
        num = (1 << 32) + num

    hash = {
        10: 'a',
        11: 'b',
        12: 'c',
        13: 'd',
        14: 'e',
        15: 'f', 
    }

    hex = ''
    while (num != 0):
        tmp = num % 16
        
        if (tmp >= 10):
            hex += hash[tmp]
        else:
            hex += str(tmp)

        num //= 16

    return hex[::-1]


toHex(-1)