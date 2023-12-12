def isIsomorphic(s: str, t: str) -> bool:
    if (len(s) != len(t)):
        return False

    counter = {}

    for i in range(len(s)):
        if (s[i] in counter):
            if counter[s[i]] != t[i]:
                return False 
        elif (t[i] not in counter.values()):
            counter[s[i]] = t[i]
        else:
            return False
    return True


def isIsomorphic(s: str, t: str) -> bool:
    zipped = set(zip(s, t))
    if len(zipped)==len(set(s))== len(set(t)):
        return True
    else:
        return False


print(isIsomorphic("paper", "title"))