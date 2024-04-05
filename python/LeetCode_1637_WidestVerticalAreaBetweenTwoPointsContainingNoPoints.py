def maxWidthOfVerticalArea(points) -> int:
    arr_x = []
    for n in points:
        arr_x.append(n[0])

    arr_x = sorted(arr_x)
    diff = 0
    for i in range(len(arr_x) - 1):
        tmp = arr_x[i + 1] - arr_x[i]
        if (tmp > diff):
            diff = tmp 

    return diff