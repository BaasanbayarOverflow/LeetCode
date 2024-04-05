#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* getMiddle(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


struct ListNode* merge(struct ListNode* x, struct ListNode* y) {
    if (x == NULL) {
        return y; 
    }

    if (y == NULL) {
        return x;
    }

    struct ListNode* tmp;
    if (x->val <= y->val) {
        tmp = x;
        tmp->next = merge(x->next, y);
    } else {
        tmp = y;
        tmp->next = merge(x, y->next);
    }

    return tmp;
}


struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* middle = getMiddle(head);
    struct ListNode* midNxt = middle->next;

    middle->next = NULL;

    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(midNxt);
    return merge(left, right);
}


int main() {
    return 0;
}