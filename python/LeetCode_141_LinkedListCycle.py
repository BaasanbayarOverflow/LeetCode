class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def hasCycle(head) -> bool:
    if not head: return False

    slow = fast = head
    while (slow and fast and fast.next):
        slow = slow.next
        fast = fast.next.next
        if (slow == fast): return True

    return False


nodes = ListNode(3)
nodes.next = ListNode(2)
nodes.next.next = ListNode(1)
nodes.next.next.next = ListNode(0)
nodes.next.next.next.next = nodes.next.next

print(hasCycle(nodes))