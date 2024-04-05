class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def sortedListToBST(head):
    if head is None:
        return None
    if head.next is None:
        return TreeNode(head.val)
    
    slow, fast = head, head
    midd = slow
    while slow and fast and fast.next:
        midd = slow
        slow = slow.next
        fast = fast.next.next
    midd.next = None

    tree = TreeNode(slow.val)
    tree.left = sortedListToBST(head)
    tree.right = sortedListToBST(slow.next)
    return tree


link = ListNode(-10)
link.next = ListNode(-3)
link.next.next = ListNode(-1)
link.next.next.next = ListNode(0)
link.next.next.next.next = ListNode(7)
#link.next.next.next.next.next = ListNode(9)
print(sortedListToBST(link))