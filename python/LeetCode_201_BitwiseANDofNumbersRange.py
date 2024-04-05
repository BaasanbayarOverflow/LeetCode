def rangeBitwiseAnd(left: int, right: int) -> int:
    while right > left:
        right &= (right - 1)
    return right


rangeBitwiseAnd(5, 7)