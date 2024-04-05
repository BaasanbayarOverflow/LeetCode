def isAnagram(s: str, t: str) -> bool:
    len_s = len(s)
    len_t = len(t)
    if (len_s != len_t): return 0
    
    hash = {}
    for letter in s:
        if letter in hash:
            hash[letter] += 1
        else:
            hash[letter] = 1
    
    for letter in t:
        if letter in hash:
            hash[letter] -= 1 
        else:
            return 0

        if hash[letter] < 0:
            return 0

    return 1


isAnagram("anagram", "nagaram")