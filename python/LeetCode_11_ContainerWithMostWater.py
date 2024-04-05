class Solution:
    def maxArea(self, height: List[int]) -> int:
        low = 0
        high = len(height) - 1
        max_volume = 0
        while (low < high):
            min_m = min(height[low], height[high])
            volume = (high - low) * min_m
            if (volume > max_volume):
                max_volume = volume

            if (height[low] > height[high]):
                high -= 1
            else:
                low += 1
        return max_volume