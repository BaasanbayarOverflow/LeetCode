def numTrees(n: int) -> int:
    mem = [1] * (n + 1)

    for branches in range(2, n + 1):
        total = 0
        for root in range(1, branches + 1):
            left = root - 1
            right = branches - root
            total += mem[left] * mem[right]
        mem[branches] = total 

    return mem[n]


print(numTrees(3))