class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def mergeInBetween(list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
    head = curr = list1

    for _ in range(a - 1):
        curr = curr.next

    scurr = curr.next
    curr.next = list2
    while curr.next:
        curr = curr.next
    
    for _ in range(b - a + 1):
        scurr = scurr.next

    curr.next = scurr
    return head


list1 = ListNode(10)
list1.next = ListNode(1)
list1.next.next = ListNode(13)
list1.next.next.next = ListNode(6)
list1.next.next.next.next = ListNode(9)
list1.next.next.next.next.next = ListNode(5)

list2 = ListNode(1000000)
list2.next = ListNode(1000001)
list2.next.next = ListNode(1000002)

print(mergeInBetween(list1, 3, 4, list2))
    
