class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseKGroup(self, head, k: int):
        def reverse(head):
            curr, prev = head, None
            while curr:
                tmp = curr.next
                curr.next = prev
                prev = curr
                curr = tmp
            return prev

        def getLast(head, lim = 0):
            if lim == 0:
                while head and head.next:
                    head = head.next
                return head

            try:
                while lim > 0:
                    head = head.next
                    lim -= 1
                return head
            except:
                return None

        if not head or not head.next or k <= 1:
            return head

        curr = head
        isFirst = True
        circle = 1
        while curr:
            inx = k
            last = getLast(curr, inx - 1)
            if not last:
                break

            tmp = last.next
            last.next = None
            curr = reverse(curr)
            last = getLast(curr)
            last.next = tmp

            if isFirst:
                head = curr
                isFirst = False
            else:
                last = getLast(head, (circle * inx) - 1)            
                last.next = curr
                circle += 1

            try:
                while inx > 0:
                    curr = curr.next
                    inx -= 1
            except:
                break

        return head  