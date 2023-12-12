#include <stdio.h>
#include <stdlib.h>


typedef enum {true, false} bool;


int getLength(struct ListNode* root) {
    struct ListNode* curr = root;
    
    int len = 0;
    while (curr != NULL) {
        ++len;
        curr = curr->next;
    }

    return len;
}


bool isPalindrome(struct ListNode* head) {
    if (head == NULL) return 1; 

    int len = getLength(head);

    int* arr = malloc((len + 10) * sizeof(int));
    for (int i = 0; i < len; ++i) {
        arr[i] = head->val;
        head = head->next;
    }

    int j = len - 1;
    for (int i = 0; i < len / 2; ++i) {
        if (arr[i] != arr[j]) {
            return 0;
        }
        --j;
    }


    return 1;
}