#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL) {
        return 0;
    }

    int carry = head->val;
    struct ListNode* current = NULL;
    current = head;
    
    while (current->next != NULL) {
        if (carry == current->next->val) {
            if (current->next->next != NULL) {
                current->next = current->next->next;
                //carry = current->val;
                continue;
            } 

            current->next = NULL;
        } else {
            current = current->next;
            carry = current->val;
        }
    }

    return head;
}

struct ListNode* append(struct ListNode* head, int val) {
    struct ListNode* node = NULL;
    node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    
    if (head == NULL) {
        return node;
    }

    struct ListNode* current = NULL;
    current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = node;

    return head;
}

int main() {
    int n = 0;
    struct ListNode *list = NULL; 

    printf_s("n - ");
    scanf_s("%d", &n);

    for (int i = 0; i < n; i++) {
        int tmp = 0;
        printf_s("element[%d] - ", i);
        scanf_s("%d", &tmp);
        list = append(list, tmp);
    }

    deleteDuplicates(list);

    free(list);

    return 0;
}