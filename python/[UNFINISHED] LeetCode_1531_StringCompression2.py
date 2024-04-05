from collections import Counter
from collections import OrderedDict


def getWord(hash, k):
    word = ''
    for key, val in hash.items():
        if (k > val):
            k -= val
            hash[key] = 0
        else:
            hash[key] -= k
            k = 0

        if (hash[key] > 0):
            point = str(hash[key]) if hash[key] != 1 else ''
            word += (key + point)
    return word


def getLengthOfOptimalCompression(s: str, k: int) -> int:
    hash = Counter(s)
    hash_asc = {key: v for key, v in sorted(hash.items(), key=lambda item: item[1])}
    
    word_asc = getWord(hash_asc, k)
    word_dec = getWord(OrderedDict(hash), k)

    l_a = len(word_asc)
    l_d = len(word_dec)

    return l_a if (l_a < l_d) else l_d



print(getLengthOfOptimalCompression("bababbaba", 1))