def maximumOddBinaryNumber(s: str) -> str:
    ones = s.count('1')
    return ("1" * (ones - 1)) + ("0" * (len(s) - ones)) + "1"


maximumOddBinaryNumber("0110")