def exist(board, word: str) -> bool:
    def dfs(i, j, inx):
        if inx == len(word):
            return True
        
        if i < 0 or j < 0 or i >= len(board) or j >= len(board[0]) or board[i][j] != word[inx]:
            return False

        mem = board[i][j]
        board[i][j] = ''

        if dfs(i, j - 1, inx + 1) or dfs(i, j + 1, inx + 1) or dfs(i - 1, j, inx + 1) or dfs(i + 1, j, inx + 1):
            return True
            
        board[i][j] = mem
        return False 
    

    for i in range(len(board)):
        for j in range(len(board[0])):
            if dfs(i, j, 0):
                return True

    return False


print(exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], "ABCCED"))