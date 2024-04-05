def cherryPickup(grid) -> int:
    rows = len(grid)
    cols = len(grid[0])

    mem = {}
    def dfs(r, c_1, c_2):
        if (r, c_1, c_2) in mem:
            return mem[(r, c_1, c_2)]
        
        if c_1 == c_2 or min(c_1, c_2) < 0 or max(c_1, c_2) == cols:
            return 0    
        
        if r == rows - 1:
            return grid[r][c_1] + grid[r][c_2]
        
        res = 0
        lims = [-1, 0, 1]
        for c1_d in lims:
            for c2_d in lims:
                res = max(res, dfs(r + 1, c_1 + c1_d, c_2 + c2_d))

        mem[(r, c_1, c_2)] = res + grid[r][c_1] + grid[r][c_2]
        return mem[(r, c_1, c_2)]
    
    return dfs(0, 0, cols - 1)


print(cherryPickup())