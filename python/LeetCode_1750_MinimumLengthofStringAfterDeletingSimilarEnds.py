class Solution:
    def minimumLength(self, s: str) -> int:
        low, high = 0, len(s) - 1
        while low < high and s[low] == s[high]:
            tmp = s[low]
            low += 1
            high -= 1
            while low <= high and s[low] == tmp:
                low += 1
            while low <= high and s[high] == tmp:
                high -= 1
        return high - low + 1