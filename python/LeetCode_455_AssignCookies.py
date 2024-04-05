def findContentChildren(g, s) -> int:
    if (len(s) <= 0 or len(g) <= 0): return 0

    s = sorted(s)
    g = sorted(g)

    total = 0 
    i, j = 0, 0
    while (i < len(s) and j < len(g)):
        if (s[i] >= g[j]):
            total += 1
            j += 1

        i += 1

    return total


findContentChildren([1,2,3], [3])