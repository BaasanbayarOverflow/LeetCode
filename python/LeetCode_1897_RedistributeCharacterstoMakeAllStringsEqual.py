from collections import defaultdict


def makeEqual(words) -> bool:
    length = len(words)
    if (length <= 1): return 1

    hash = defaultdict(int)
    for word in words:
        for letter in word:
            hash[letter] += 1

    for v in hash.values():
        if v % length != 0:
            return False

    return True


print(makeEqual(["b","a"]))