class Solution:
    def findMinimumOperations(self, s1: str, s2: str, s3: str) -> int:
        low = min(min(len(s1), len(s2)), len(s3))

        prefix = ''
        for i in range(low):
            if (s1[i] == s2[i] == s3[i]):
                prefix += s1[i]
            else:
                break

        if len(prefix) == 0: return -1
        return (len(s1) + len(s2) + len(s3)) - len(prefix) * 3