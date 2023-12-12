#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


int getLength(struct ListNode* head) {
    struct ListNode* temp = head; 

    int counter = 1; 
    while (temp->next != NULL) {
        ++counter;
        temp = temp->next;  
    }

    return counter;
}


struct ListNode* findIntersection(struct ListNode* l1, struct ListNode* l2) {


    do {
        if (l1 == l2) {
            return l1;
        }
        l1 = l1->next;
        l2 = l2->next;
    } while (l1 != NULL && l2 != NULL);

    return NULL;
}


struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }

    int l1 = getLength(headA);
    int l2 = getLength(headB);
    int diff = abs(l1 - l2);
    struct ListNode* tmp = NULL;

    if (l1 > l2) {
        for (int i = 0; i < diff; i++) {
            headA = headA->next;
        }

        tmp = findIntersection(headA, headB);    
    } else if (l1 < l2) {
        for (int i = 0; i < diff; i++) {
            headB = headB->next;
        }

        tmp = findIntersection(headA, headB);
    } else {
        tmp = findIntersection(headA, headB);
    }

    return tmp; 
}


struct ListNode* push(struct ListNode* head, int val) {
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->next = head;
    node->val = val; 
    return node;     
}


int main() {
    struct ListNode* l_1 = NULL; 
    struct ListNode* l_2 = NULL;

    l_1 = push(l_1, 4);
    l_1 = push(l_1, 5);
    l_1 = push(l_1, 4);

    l_2 = push(l_1, 2);
    l_2 = push(l_2, 2);
    //l_2 = push(l_2, 5);

    l_1 = push(l_1, 2);
    l_1 = push(l_1, 2);

    getIntersectionNode(l_1, l_2);

    return 0;
}