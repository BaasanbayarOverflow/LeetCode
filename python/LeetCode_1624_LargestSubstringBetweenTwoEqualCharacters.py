from collections import defaultdict


def maxLengthBetweenEqualCharacters(s: str) -> int:
    if len(set(s)) == len(s): return -1

    hash = defaultdict(list)
    for i, n in enumerate(s):
        hash[n].append(i)

    mmax = 0
    for v in hash.values():
        if (len(v) <= 1):
            continue

        mmax = max(mmax, v[len(v) - 1] - v[0])

    return mmax - 1


maxLengthBetweenEqualCharacters("mgntdygtxrvxjnwksqhxuxtrv")