class Solution:
    def maxScore(self, s: str) -> int:
        length = len(s)
        mmax = 0
        for i in range(1, length):
            zeros = 0
            ones = 0 

            for x in range(i):
                if (s[x] == '0'):
                    zeros += 1

            for y in range(i, length):
                if (s[y] == '1'):
                    ones += 1

            summ = zeros + ones 
            mmax = summ if summ > mmax else mmax 
        return mmax