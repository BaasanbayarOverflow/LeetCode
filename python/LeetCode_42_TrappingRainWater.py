class Solution:
    def trap(self, height) -> int:
        result = 0
        
        low = height[0]
        high = height[len(height) - 1]

        i = 0
        inx = len(height) - 1
        while i < inx:
            if low <= high:
                result += low - height[i]
                i += 1
                low = max(low, height[i])
            else:
                result += high - height[inx]
                inx -= 1
                high = max(high, height[inx])

        return result