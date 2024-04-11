from collections import Counter

class Solution:
    def intersect(self, nums1, nums2):
        n_1 = Counter(nums1)
    
        result = []
        for n in nums2:
            if n in n_1 and n_1[n] > 0:
                result.append(n)
                n_1[n] -= 1

        return result