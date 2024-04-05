def expand(s, low, high):
    while (low >= 0 and high < len(s) and s[low] == s[high]):
        low -= 1
        high += 1
    
    return s[low + 1 : high]


def longestPalindrome(s: str) -> str:
    palindrome = ''
    for i in range(len(s)):
        word = expand(i, i)
        if (len(palindrome) < len(word)):
            palindrome = word
        word = expand(i, i + 1)
        if (len(palindrome) < len(word)):
            palindrome = word 

    return palindrome