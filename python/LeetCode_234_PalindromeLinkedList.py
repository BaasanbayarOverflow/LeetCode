class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        l = []
        while (head != None):
            l.append(head.val)
            head = head.next

        rev_list = l[::-1]
        return 1 if rev_list == l else 0
        