def merge(intervals):
    if (len(intervals) <= 0):
        return intervals

    start = []
    end = []
    for i in intervals:
        start.append(i[0])
        end.append(i[1])

    start = sorted(start)
    end = sorted(end)

    result = []
    first, second = start[0], 0
    flag = 1
    i = 1
    while (i < len(start)):
        if (start[i] <= end[i - 1]):
            second = end[i]
            flag = 0
        else:
            if (flag):
                second = end[i - 1]
            result.append([first, second])
        
            first = start[i]
            flag = 1
        i += 1
            
    second = (end[len(end) - 1])
    result.append([first, second])
    return result


merge([[1,4],[0,4]])