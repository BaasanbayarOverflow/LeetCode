def rotate(nums, k):
    length = len(nums)

    k = length - (k % length)
    tmp = [0 for _ in range(length)]

    inx = 0
    for i in range(k, length):
        tmp[inx] = nums[i]
        inx += 1

    for i in range(k):
        tmp[inx] = nums[i]
        inx += 1

    for i in range(length):
        nums[i] = tmp[i]


rotate([1,2,3,4,5,6,7], 6)



"""
def rotate(nums, k: int) -> None:
    tmp = 0 
    k = k % len(nums)
    for _ in range(k):
        tmp = nums.pop()
        nums.insert(0, tmp)
"""