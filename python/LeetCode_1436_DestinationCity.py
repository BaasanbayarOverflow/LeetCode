# Optimal Solution

"""
def destCity(self, paths: List[List[str]]) -> str:
    s=set()
    l=set()
    for i in paths:
        s.add(i[0])
        l.add(i[1])
    return list(l-s)[0]
"""


def destCity(paths) -> str:
    source = [loc[0] for loc in paths]
    destination = [loc[-1] for loc in paths]

    res = ''
    for d in destination:
        if d not in source:
            res = d
    return res


destCity([["B","C"],["D","B"],["C","A"]])