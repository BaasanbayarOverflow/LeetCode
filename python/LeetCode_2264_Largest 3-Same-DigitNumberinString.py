class Solution:
    def largestGoodInteger(self, num: str) -> str:
        tmp = '+'
        for i in range(len(num) - 2):
            if (num[i] == num[i + 1] and num[i] == num[i + 2]):
                if (tmp < num[i]):
                    tmp = num[i]

        return "".join([tmp * 3]) if tmp != '+' else ''