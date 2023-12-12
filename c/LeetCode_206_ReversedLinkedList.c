#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* insert(struct ListNode* head, int val) {
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->next = head; 
    node->val = val;
    return node;
}


struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    struct ListNode* rev_head = NULL;
    while (head->next != NULL) {
        rev_head = insert(rev_head, head->val);

        head = head->next;
    }

    rev_head = insert(rev_head, head->val);    
    return rev_head;
}


int main() {
    struct ListNode* head = NULL; 
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);

    reverseList(head);

    return 0;
}