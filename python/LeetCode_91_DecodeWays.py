def numDecodings(s: str) -> int:
    if s[0] == '0':
        return 0 
    
    tmp_2 = 1 
    tmp_1 = int(s[-1] != "0")

    i = len(s) - 2
    while (i >= 0):
        if s[i] == '0':
            tmp_0 = 0
        else:
            tmp_0 = tmp_1 
            if s[i] == '1' or (s[i] == '2' and s[i + 1] < '7'):
                tmp_0 += tmp_2
    
        i -= 1
        tmp_0, tmp_1, tmp_2 = 0, tmp_0, tmp_1 
    return tmp_1     
   

print(numDecodings("1206"))