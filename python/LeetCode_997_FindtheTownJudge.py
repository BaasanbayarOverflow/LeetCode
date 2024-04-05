from collections import defaultdict

def findJudge(n: int, trust) -> int:
    incoming = defaultdict(int)
    outgoing = defaultdict(int)
    for edge in trust:
        incoming[edge[0]] += 1
        outgoing[edge[1]] += 1

    for i in range(1, n + 1):
        if incoming[i] == 0 and outgoing[i] == n - 1:
            return i

    return -1