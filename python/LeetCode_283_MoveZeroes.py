def moveZeroes(nums):
    l = len(nums)
    inx = 0
    zeros = 0

    while (inx < l):
        if (nums[inx] == 0):
            nums.pop(inx)
            zeros += 1
            inx -= 1
            l -= 1
        inx += 1

    if zeros > 0:
        for i in range(zeros):
            nums.append(0)


def main():
    moveZeroes([0, 1, 0, 3, 12])