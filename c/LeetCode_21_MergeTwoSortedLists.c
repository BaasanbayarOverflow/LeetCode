#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* new_list = NULL;
    struct ListNode* current = NULL;
    while (list1 != NULL || list2 != NULL) {
        if (list1 != NULL && list2 != NULL) {
            if (list1->val >= list2->val) {
                if (new_list == NULL) {
                    new_list = list2;
                    current = new_list;
                } else {
                    current->next = list2;
                    current = current->next;
                }
                list2 = list2->next;
            } else {
                if (new_list == NULL) {
                    new_list = list1;
                    current = new_list;
                } else { 
                    current->next = list1;
                    current = current->next;
                }
                list1 = list1->next;
            }
        } else if (list1 == NULL) {
            if (new_list == NULL) {
                new_list = list2;
                current = new_list;
            } else {
                current->next = list2;
                current = current->next;
            }
            list2 = list2->next;
        } else if (list2 == NULL) {
            if (new_list == NULL) {
                new_list = list1;
                current = new_list;
            } else { 
                current->next = list1;
                current = current->next;
            }
            list1 = list1->next;
        } else {
            break;
        }
    }
    return new_list;
}


int main() {
	struct node* head = NULL;
	struct node* current = NULL;
	return 0;
}