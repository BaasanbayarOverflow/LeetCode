from collections import deque

def rearrangeArray(nums):
    n_p = []
    n_n = deque()
    for n in nums:
        if n > -1:
            n_p.append(n)
            n_p.append(0)
        else:
            n_n.append(n)
    
    for i in range(len(nums)):
        if i % 2 == 1:
            n_p[i] = n_n.popleft()
    return n_p


print(rearrangeArray([3,1,-2,-5,2,-4]))