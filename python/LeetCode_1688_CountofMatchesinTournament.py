def numberOfMatches(n: int) -> int:
    matches = 0
    while (n // 2 != 0):
        rem = n % 2
        n = n // 2 
        matches += n
        n = n + rem
    return matches 


print(numberOfMatches(14))