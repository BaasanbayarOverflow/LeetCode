def maxProfit(prices) -> int:
    start, result = prices[0], 0
     
    for i in range(1, len(prices)):
        if (start > prices[i]):
            start = prices[i]
        elif (prices[i] - start > result):
            result = prices[i] - start 
    return result


print(maxProfit([2, 4, 1]))