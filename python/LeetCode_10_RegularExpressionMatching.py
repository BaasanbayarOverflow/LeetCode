def isMatch(s: str, p: str) -> bool:
    vertical = len(s)
    horizontal = len(p)

    if vertical == 0 and horizontal == 0:
        return True 
    elif horizontal == 0:
        return False 
    
    matrix = [[0 for _ in range(horizontal + 1)] for _ in range(vertical + 1)]
    matrix[0][0] = 1

    for i in range(2, horizontal + 1):
        if p[i - 1] == '*':
            matrix[0][i] = matrix[0][i - 2]
    
    for i in range(1, vertical + 1):
        for j in range(1, horizontal + 1):
            if (s[i - 1] == p[j - 1]) or (p[j - 1] == '.'):
                matrix[i][j] = matrix[i - 1][j - 1]
            elif (j > 1) and (p[j - 1] == '*'):
                matrix[i][j] = matrix[i][j - 2]
                if (p[j - 2] == '.') or (p[j - 2] == s[i - 1]):
                    matrix[i][j] = matrix[i][j] or matrix[i - 1][j]
    
    return matrix[vertical][horizontal]


isMatch("aa", "a*")