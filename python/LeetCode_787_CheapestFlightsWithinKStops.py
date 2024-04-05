from collections import defaultdict
from collections import deque

def findCheapestPrice(n: int, flights, src: int, dst: int, k: int) -> int:
    adj = defaultdict(list)
    visited = [float('inf')] * n
    visited[src] = 0

    for f in flights:
        adj[f[0]].append((f[1], f[2]))

    queue = deque([(src, 0)])
    k += 1

    while k > 0 and queue:
        size = len(queue)
        while size > 0:
            curr_n, curr_p = queue.popleft()
            for neighbor, price in adj[curr_n]:
                new_price = curr_p + price 
                if new_price < visited[neighbor]:
                    visited[neighbor] = new_price
                    queue.append((neighbor, new_price))
            size -= 1
        k -= 1
    
    return visited[dst] if visited[dst] != float('inf') else -1


print(findCheapestPrice(4, [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], 0, 3, 1))