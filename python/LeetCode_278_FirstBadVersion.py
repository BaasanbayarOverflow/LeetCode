class Solution:
    def firstBadVersion(self, n: int) -> int:
        low = 0
        high = n
        mid = 0

        while (low < high):
            mid = low + (high - low) // 2
            if (isBadVersion(mid)):
                high = mid
            else: 
                low = mid + 1
        return low