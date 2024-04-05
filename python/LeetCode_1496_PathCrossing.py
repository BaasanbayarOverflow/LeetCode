def isPathCrossing(path: str) -> bool:
    points = {}
    location = [0, 0]
    for p in path:
        points[str(location[0]) + '-' + str(location[1])] = 1

        if (p == 'N'):
            location[1] += 1
        elif (p == 'S'):
            location[1] -= 1
        elif (p == 'E'):
            location[0] -= 1
        elif (p == 'W'):
            location[0] += 1

        key = str(location[0]) + '-' + str(location[1])
        if key in points.keys():
            return 1 
    return 0


print(isPathCrossing('ENNNNNNNNNNNEEEEEEEEEESSSSSSSSSS'))