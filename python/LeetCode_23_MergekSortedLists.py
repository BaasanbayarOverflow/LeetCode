class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def mergeKLists(lists):
    result = []
    for arr in lists:
        while(arr):
            result.append(arr.val)
            arr = arr.next

    l = sorted(result, reverse=True)
    chain = None
    for n in l:
        node = ListNode(n)
        if (chain == None):
            chain = node 
        else:
            node.next = chain
            chain = node

    return chain
    




mergeKLists([[1,4,5],[1,3,4],[2,6]])



"""
length = len(lists)
    inxs = [0] * length
    lnxs = [len(arr) for arr in lists]

    result = []
    l = length(result)
    while (l < sum(lnxs)):
        for arr in lists:
            

    pass 
"""