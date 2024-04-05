#include <stdio.h>
#include <stdlib.h>


/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head == NULL) {
        return NULL;
    }
    
    int length = 0;
    struct ListNode* tmp = head;
    while (tmp) {
        ++length;
        tmp = tmp->next;
    }

    int nth = length - n + 1;
    if (nth >= 0) {
        struct ListNode* prev = NULL;
        tmp = head;
        for (int i = 1; i < nth; ++i) {
            prev = tmp;
            tmp = tmp->next;
        }
        
        if (prev == NULL) {
            head = head->next;
        } else {
            prev->next = prev->next->next;
        }
        return head;
    } 
    
    return head;
}


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head == NULL) {
        return NULL;
    }
    
    int length = 0;
    struct ListNode* tmp = head;
    while (tmp) {
        ++length;
        tmp = tmp->next;
    }

    int nth = length - n;
    if (nth == 0) {
        head = head->next;
    } else if (nth > 0) {
        tmp = head;
        for (int i = 1; i < nth; ++i) {
            tmp = tmp->next;
        }

        tmp->next = tmp->next->next;
    } 
    
    return head;
}

*/

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head == NULL) {
        return NULL;
    }
    
    struct ListNode *fast = head;
    struct ListNode *slow = head;

    for (int i = 0; i < n; ++i) {
        fast = fast->next;
    }

    if (fast == NULL) {
        return head->next;
    }

    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return head;
}