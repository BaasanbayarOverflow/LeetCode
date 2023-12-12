def intersection(nums1, nums2):
    intersection = []

    nums1 = set(nums1)
    nums2 = set(nums2)

    for n in nums1:
        if n in nums2:
            intersection.append(n)

    return intersection


intersection()