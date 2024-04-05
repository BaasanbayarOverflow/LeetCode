def check(word, i, j, lim):
    while (i >= 0 and j < lim):
        if word[i] != word[j]:
            return False 
        i -= 1
        j += 1
    return True


def firstPalindrome(words) -> str:
    for word in words:
        lngth = len(word)
        i = lngth // 2
        tmp = 0
        if lngth % 2 == 0:
            tmp = check(word, i - 1, i, lngth)
        else: 
            tmp = check(word, i, i, lngth)

        if tmp: return word

    return ""


print(firstPalindrome(["poop","zsz"]))