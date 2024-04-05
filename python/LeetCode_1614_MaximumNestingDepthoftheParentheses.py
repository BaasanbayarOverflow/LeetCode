def maxDepth(s: str) -> int:
    result = 0
    counter = 0
    for i in range(len(s)):
        if (s[i] == "("):
            counter += 1
        elif (s[i] == ")"):
            counter -= 1
        result = max(result, counter)

    return result


print(maxDepth("(1+(2*3)+((8)/4))+1"))