from typing import List
from collections import defaultdict


class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        def traverse(root, visited):
            if root == destination:
                return True
            
            visited.add(root)
            for g in graph[root]:
                if g not in visited:
                    if traverse(g, visited):
                        return True
            return False

        return traverse(source, set())
        