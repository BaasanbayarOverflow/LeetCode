from typing import List

class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        xLen = len(land)
        yLen = len(land[0])
        self.visited = [[0 for _ in range(yLen)] for _ in range(xLen)]

        self.result = []
        for i in range(xLen):
            for j in range(yLen):
                if land[i][j] == 1 and not self.visited[i][j]:
                    tmp = [i, j]
                    tmp.extend(self.traverse(land, i, j))
                    self.result.append(tmp)

        return self.result


    def traverse(self, land, i, j):
        tmp = [i, j]
        
        self.visited[i][j] = 1      
        if i + 1 < len(land) and j + 1 < len(land[0]) and land[i + 1][j] == 1 and land[i][j + 1] == 1 and land[i + 1][j + 1] == 1:
            x = 0
            while (i + x < len(land) and land[i + x][j] == 1):
                self.visited[i + x][j] = 1
                x += 1

            y = 0
            while (j + y < len(land[0]) and land[i][j + y] == 1):
                self.visited[i][j + y] = 1
                y += 1    

            tmp = self.traverse(land, i + 1, j + 1)
        elif i + 1 < len(land) and j < len(land[0]) and land[i + 1][j] == 1:
            tmp = self.traverse(land, i + 1, j)
        elif j + 1 < len(land[0]) and i < len(land) and land[i][j + 1] == 1:
            tmp = self.traverse(land, i, j + 1)

        return tmp