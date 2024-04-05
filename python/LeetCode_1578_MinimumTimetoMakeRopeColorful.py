def minCost(colors: str, neededTime) -> int:
    total = 0
    for i in range(1, len(colors)):
        if (colors[i] == colors[i - 1]):
            total += min(neededTime[i], neededTime[i - 1])
            neededTime[i] = max(neededTime[i], neededTime[i - 1])

    return total


minCost("aaabbbabbbb", [3,5,10,7,5,3,5,5,4,8,1])