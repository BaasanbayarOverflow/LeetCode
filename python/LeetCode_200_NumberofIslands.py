from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        self.xLen = len(grid)
        self.yLen = len(grid[0])

        self.visited = [[0 for _ in range(self.yLen)] for _ in range(self.xLen)]
        self.result = 0

        for i in range(self.xLen):
            for j in range(self.yLen):
                if self.visited[i][j] == 0 and grid[i][j] == '1':
                    self.traverse(grid, i, j)
                    self.result += 1

        return self.result


    def traverse(self, grid, i, j):
        dirs = [
            [-1, 0],
            [0, 1],
            [1, 0],
            [0, -1]
        ]

        self.visited[i][j] = 1
        for dir in dirs:
            x, y = i + dir[0], j + dir[1]
            if x >= 0 and x < self.xLen and y >= 0 and y < self.yLen:
                if not self.visited[x][y] and grid[x][y] == '1':
                    self.traverse(grid, x, y)