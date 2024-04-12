class Solution:
    def findKOr(self, nums, k: int) -> int:
        binaries = [0] * 31

        for n in nums:
            tmp = bin(n)[2:][::-1]
            for i in range(len(tmp)):
                if tmp[i] == '1':
                    binaries[i] += 1
        
        result = '0'
        flag = 0
        for i in range(30, -1, -1):
            if binaries[i] >= k:
                result += '1'
                flag = 1
            elif flag:
                result += '0'
        
        return int(result, 2)