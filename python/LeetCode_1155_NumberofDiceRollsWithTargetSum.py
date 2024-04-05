def numRollsToTarget(n: int, k: int, target: int) -> int:
    if ((n * k) < target):
        return 0 

    mod = 10 ** 9 + 7 
    dp = [[0 for _ in range(target + 1)] for _ in range(n + 1)]
    dp[0][0] = 1

    for i in range(1, n + 1):
        j_lim = min(i * k, target) + 1
        for j in range(i, j_lim):
            for x in range(1, min(k, j) + 1):
                dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % mod 
    
    return int(dp[n][target])


numRollsToTarget(2, 6, 7)