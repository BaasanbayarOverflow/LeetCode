from collections import deque

class Solution:
    def swapPairs(self, head):
        if not head or not head.next: return head

        odd = deque()
        even = deque()

        inx = 0
        curr = head
        while (curr):
            if inx % 2 == 0:
                even.append(curr.val)
            else:
                odd.append(curr.val)
            curr = curr.next
            inx += 1

        inx = 0
        curr = head
        while (curr):
            if inx % 2 == 0:
                try:
                    curr.val = odd.popleft()
                except:
                    pass
            else:
                try:
                    curr.val = even.popleft()
                except:
                    pass
            curr = curr.next
            inx += 1

        return head            