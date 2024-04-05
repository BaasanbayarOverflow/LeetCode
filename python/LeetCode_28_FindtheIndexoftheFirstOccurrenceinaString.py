def strStr(haystack: str, needle: str) -> int:
    len_h = len(haystack)
    len_n = len(needle)

    for i in range(len_h):
        if (haystack[i : len_n] == needle):
            return i
        len_n += 1
    return -1 


strStr("hello", "ll")