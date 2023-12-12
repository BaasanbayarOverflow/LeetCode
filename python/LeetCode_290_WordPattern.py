def wordPattern(pattern: str, s: str) -> bool:
    hash = {}

    inx = 0
    length = len(s)
    for i in range(len(pattern)):
        if (pattern[i] in hash):
            word = ''
            while (inx < length and s[inx] != ' '):
                word += s[inx]
                inx += 1

            if word !=  hash[pattern[i]]:
                return False
        else:
            tmp = ''
            while (inx < length and s[inx] != ' '):
                tmp += s[inx]
                inx += 1

            for k, v in hash.items():
                if (v == tmp): return False

            hash[pattern[i]] = tmp
        inx += 1

    if (length != inx - 1):
        return False

    return 1


print(wordPattern("abba", "dog cat cat dog"))