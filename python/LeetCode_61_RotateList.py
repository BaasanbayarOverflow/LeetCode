class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def rotateRight(head, k: int):
    if (head == None or head.next == None or k <= 0):
        return head

    tmp = head 
    counter = 0
    while (tmp.next != None):
        counter += 1
        tmp = tmp.next
    tmp.next = head

    counter += 1
    k = k % counter
    for _ in range(counter - k):
        head = head.next 

    tmp = head 
    for _ in range(counter - 1):
        tmp = tmp.next 
    tmp.next = None

    return head



l = ListNode(0)
l.next = ListNode(1)
l.next.next = ListNode(2)
#l.next.next.next = ListNode(4)
#l.next.next.next.next = ListNode(5)

rotateRight(l, 4)
        