def lengthOfLongestSubstring(s: str) -> int:
    visited = {}
    length, result = 0, 0
    for i in range(len(s)):
        if (s[i] not in visited):
            result = max(result, i - length + 1)
        else:
            if visited[s[i]] < length:
                result = max(result, i - length + 1)
            else:
                length = visited[s[i]] + 1
        visited[s[i]] = i

    return result
    

print(lengthOfLongestSubstring("dvdf"))



# BRUTE FORCE
"""
def lengthOfLongestSubstring(s: str) -> int:
    length = len(s)
    if (length == 0): return 0

    words = []
    for i in range(length, 0, -1):
        inx = 0
        while (inx + i <= length):
            word = s[inx : (i + inx)]
            inx += 1
            length_of_substring = len(word)
            length_of_set = len(set(word))
            if (length_of_substring == length_of_set):
                return len(word)        

    return 1
"""