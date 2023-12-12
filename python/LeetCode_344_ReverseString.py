class Solution:
    def reverseString(self, s: List[str]) -> None:
        low = 0
        high = len(s) - 1

        while (low < high):
            s[low], s[high] = s[high], s[low]
            low += 1
            high -= 1

        