from typing import List


class Solution:
    def check(self, grid, i, j):
        coords = [
            [-1, 0],
            [0, 1],
            [1, 0],
            [0, -1]
        ]

        counter = 0
        for coord in coords:
            x, y = i + coord[0], j + coord[1]

            if x >= 0 and x < len(grid) and y >= 0 and y < len(grid[0]):
                if grid[x][y] == 0:
                    counter += 1
            else:
                counter += 1
        return counter


    def islandPerimeter(self, grid: List[List[int]]) -> int:
        self.perimeter = 0

        xLen, yLen = len(grid), len(grid[0])
        for i in range(xLen):
            for j in range(yLen):
                if grid[i][j] == 1:
                    self.perimeter += self.check(grid, i, j)

        return self.perimeter