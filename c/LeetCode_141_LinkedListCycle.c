#include <stdio.h>
#include <stdlib.h>

typedef enum {true, false} bool;


struct ListNode {
    int val;
    struct ListNode *next;
};

/*
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return 0;
    }
   
    struct ListNode *p_1 = head;
    struct ListNode *p_2 = head;

    while (p_1 && p_2 && p_2->next != NULL) {
        p_1 = p_1->next;
        p_2 = p_2->next->next;
        
        if (p_1 == p_2) {
            return true;
        }
    }

    return false;
}
*/

bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return 0;
    }
   
    struct ListNode *p_1 = head;
    struct ListNode *p_2 = head;

    int inx = 1;

    while (p_2->next != NULL) {
        if (inx % 2 == 0) {
            p_1 = p_1->next;
        }
        p_2 = p_2->next;
        
        if (p_1 == p_2) {
            return true;
        }

        ++inx;
    }

    return false;
}


int main() {

    return 0;
}