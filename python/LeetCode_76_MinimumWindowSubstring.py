from collections import Counter


def minWindow(s: str, t: str) -> str:
    freq = Counter(t)

    i, inx = 0, 0
    mmin = 100000
    count = len(t)
    left = 0
    while inx < len(s):
        if freq[s[inx]] > 0:
            count -= 1
        
        freq[s[inx]] -= 1
        inx += 1

        while count == 0:
            if inx - i < mmin:
                left = i
                mmin = inx - i

            if freq[s[i]] == 0:
                count += 1

            freq[s[i]] += 1
            i += 1
    
    return "" if mmin == 100000 else s[left:left + mmin]


print(minWindow("ADOBECODEBANC", "ABC"))