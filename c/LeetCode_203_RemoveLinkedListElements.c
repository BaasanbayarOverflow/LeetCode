#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL) {
        return NULL;
    }

    int flag = 1;
    struct ListNode* tmp = head;
    while (tmp && tmp->next != NULL) {
        if (tmp->next->val == val) {
            flag = 0;
            if (tmp->next->next == NULL) {
                tmp->next = NULL; 
            } else {
                tmp->next = tmp->next->next;
            }
        }

        if (flag) {
            tmp = tmp->next;
        }
        flag = 1;
    }

    if (head->val == val) { 
        if (head->next == NULL) {
            return NULL;
        } 

        head = head->next;
    }

    return head;
}


struct ListNode* insert(struct ListNode* head, int val) {
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->next = head;
    node->val = val;

    return node;
}


int main() {
    struct ListNode* list = NULL;   
    
    
    list = insert(list, 7);
    list = insert(list, 7);
    list = insert(list, 7);
    list = insert(list, 7);

    /*
    list = insert(list, 6);
    list = insert(list, 5);
    list = insert(list, 4);
    list = insert(list, 3);
    list = insert(list, 6);
    list = insert(list, 2);
    list = insert(list, 1);
    */

    removeElements(list, 7);

    return 0;
}