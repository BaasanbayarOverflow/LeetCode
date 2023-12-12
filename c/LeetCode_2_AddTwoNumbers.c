#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* new_list = NULL;
 
    while (l1 != NULL || l2 != NULL) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->next = NULL;
        if (l1 == NULL) {
            node->val = l2->val;  
            l2 = l2->next;  
        } else if (l2 == NULL) {
            node->val = l1->val;
            l1 = l1->next;
        } else if (l1 != NULL && l2 != NULL) {
            node->val = l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (new_list == NULL) {
            new_list = node;
        } else {
            struct ListNode* last = new_list;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = node;
        }
    }

    bool flag = false;
    struct ListNode* current = new_list;
    while (current != NULL) {
        if (flag) {
            current->val += 1;
            flag = false;
        }
        
        if (current->val > 9) {
            current->val = current->val - 10;
            flag = true;
        }

        current = current->next;
    } 

    if (flag) {
        new_list = append(new_list, 1);
    } 

    free(current);
    
    return new_list;
}


struct ListNode* append(struct ListNode* head, int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->next = NULL;
    node->val = val;

    if (head == NULL) {
        head = node;
        return head;
    }

    struct ListNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = node;
    return head;
}


void print(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf_s("%d -> ", current->val);
        current = current->next;
    }
    printf_s("NULL\n");
}


int main() {
    struct ListNode* list_1 = NULL;
    struct ListNode* list_2 = NULL;

    int size_list_1 = 0;
    int size_list_2 = 0;

    fputs("List 1 size - ", stdout);
    scanf_s("%d", &size_list_1);

    int temp = 0;
    for (int i = 0; i < size_list_1; i++) {
        printf_s("Element[%d]: ", i);
        scanf_s("%d", &temp);
        list_1 = append(list_1, temp);
    }

    fputs("List 2 size - ", stdout);
    scanf_s("%d", &size_list_2);

    for (int i = 0; i < size_list_2; i++) {
        printf_s("Element[%d]: ", i);
        scanf_s("%d", &temp);
        list_2 = append(list_2, temp);
    }

    print(list_1);
    print(list_2);

    struct ListNode* list = addTwoNumbers(list_1, list_2);
    print(list);


    free(list_1);
    free(list_2);
    free(list);

    return 0;
}