def dailyTemperatures(temperatures):
    lngth = len(temperatures)
    result = [0 for _ in range(lngth)]
    
    stack = []
    for i in range(len(temperatures) - 1, -1, -1):
        curr = temperatures[i]

        while stack and curr >= temperatures[stack[-1]]:
            stack.pop()

        if stack:
            result[i] = stack[-1] - i
        
        stack.append(i)
    return result


print(dailyTemperatures([41,41,77]))