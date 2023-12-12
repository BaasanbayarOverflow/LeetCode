# Optimal Solution
def countBits(n):
    ans = [0] * (n + 1)
    for i in range(1, n + 1):
        x = ans[i >> 1]
        ans[i] = x + (i & 1)

    return ans


print(countBits(5))
