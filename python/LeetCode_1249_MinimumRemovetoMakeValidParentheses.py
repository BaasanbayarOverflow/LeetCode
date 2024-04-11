class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        inx = {}
    
        left = 0
        for i in range(len(s)):
            if s[i] == '(':
                left += 1
            elif s[i] == ')':
                if left == 0:
                    inx[i] = 0
                else:
                    left -= 1

        right = 0
        for i in range(len(s) - 1, -1, -1):
            if s[i] == ')':
                right += 1
            elif s[i] == '(':
                if right == 0:
                    inx[i] = 0
                else:
                    right -= 1
        
        res = ''
        for i in range(len(s)):
            if i not in inx:
                res += s[i]

        return res