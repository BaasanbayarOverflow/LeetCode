def minOperations(s: str) -> int:
    first = s[0]
    counter_1 = 0
    for i in range(1, len(s)):
        first = '0' if first == '1' else '1'
        if (first != s[i]):
            counter_1 += 1
    
    first = '0' if s[0] == '1' else '1'
    counter_2 = 0 
    for i in range(1, len(s)):
        first = '0' if first == '1' else '1'
        if (first != s[i]):
            counter_2 += 1

    return min(counter_1, counter_2 + 1)



minOperations("10010100")



"""
def minOperations(self, s: str) -> int:
    change_1 = 0
    cur = True

    for c in s:
        if cur == (c == "0"):
            change_1 += 1
        
        cur = not cur
    return min(change_1, len(s) - change_1)

"""