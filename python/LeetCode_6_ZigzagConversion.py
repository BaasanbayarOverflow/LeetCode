def convert(s: str, numRows: int) -> str:
    if (numRows == 1): return s

    main = []
    for _ in range(numRows):
        main.append([])

    inx = 0
    flag = 1
    for letter in s:
        main[inx].append(letter)
        inx += 1 if flag else -1
        
        if (inx == numRows):
            flag = 0
            inx -= 2
        elif (inx == -1):
            flag = 1
            inx += 2

    result = ''
    for word in main:
        result += ''.join(word)

    return result


print(convert("ABC", 1))