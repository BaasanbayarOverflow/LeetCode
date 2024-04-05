def maxSumAfterPartitioning(arr, k: int) -> int:
    lngth = len(arr)
    lim = k + 1

    dp = [0 for _ in range(lim)]
    for i in range(lngth - 1, -1, -1):
        mmax = 0
        mlim = min(lngth, i + k)

        for j in range(i, mlim):
            mmax = max(mmax, arr[j])
            dp[i % lim] = max(dp[i % lim], dp[(j + 1) % lim] + (mmax * (j - i + 1)))
    
    return dp[0]


maxSumAfterPartitioning([1,15,7,9,2,5,10], 3)