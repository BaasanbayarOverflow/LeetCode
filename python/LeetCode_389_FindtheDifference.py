def findTheDifference(s: str, t: str) -> str:
    sum_s = 0 
    for x in s:
        sum_s += ord(x)
    
    sum_t = 0
    for x in t:
        sum_t += ord(x)

    return chr(abs(sum_s - sum_t))


findTheDifference("abcd", "abcde")