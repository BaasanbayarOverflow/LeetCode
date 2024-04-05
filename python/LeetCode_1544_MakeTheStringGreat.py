def makeGood(s: str) -> str:
    i = 0
    while (i < len(s) - 1):
        if (ord(s[i]) - 32 == ord(s[i + 1])):
            s = s[0 : i] + s[i + 2 : len(s)]
            i = 0
            continue
        i += 1
    return s


print(makeGood(''))