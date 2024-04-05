class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def insertionSortList(head):
    curr = head
    while (curr):
        prev = head

        while (prev != curr):
            if (curr.val < prev.val):
                prev.val, curr.val = curr.val, prev.val

            prev = prev.next
        curr = curr.next

    return head


x = ListNode(4)
x.next = ListNode(2)
x.next.next = ListNode(1)
x.next.next.next = ListNode(3)

insertionSortList(x)


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


"""def insertionSort(arr):
    for i in range(1, len(arr)):
        tmp = arr[i]
        j = i - 1
        while (j >= 0 and tmp < arr[j]):
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = tmp


def insertionSortList(head):
    arr = []
    tmp = head
    while (tmp):
        arr.append(tmp.val)
        tmp = tmp.next
    
    insertionSort(arr)
    
    tmp = head
    for n in arr:
        tmp.val = n
        tmp = tmp.next
    return head
"""



x = ListNode(4)
x.next = ListNode(2)
x.next.next = ListNode(1)
x.next.next.next = ListNode(3)

insertionSortList(x)