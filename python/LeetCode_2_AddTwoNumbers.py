class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def insert(linkedlist, val):
    tmp = ListNode(val)
    tmp.next = linkedlist
    return tmp


def addTwoNumbers(l1, l2):
    if l1 == None:
        return l2 
    
    if l2 == None:
        return l1 
    
    num_1 = ''
    while (l1 != None):
        num_1 += str(l1.val)
        l1 = l1.next

    num_2 = ''
    while (l2 != None):
        num_2 += str(l2.val)
        l2 = l2.next
 
    total = int(num_1[::-1]) + int(num_2[::-1])
    if (total == 0): return ListNode()

    result = None
    total = str(total)[::-1]
    for n in total:
        result = insert(result, int(n))
        
    return result


l1 = ListNode(2)
l1.next = ListNode(4)
l1.next.next = ListNode(3)

l2 = ListNode(5)
l2.next = ListNode(6)
l2.next.next = ListNode(4)
#l2.next.next.next = ListNode(9)

addTwoNumbers(l1, l2)
