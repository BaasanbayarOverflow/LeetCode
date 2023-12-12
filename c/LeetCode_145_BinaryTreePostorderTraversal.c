#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct Stack
{
    struct TreeNode* node;
    struct Stack *next;
};


struct Stack* push(struct Stack* s, struct TreeNode* node) {
    struct Stack* new = (struct Stack*) malloc(sizeof(struct Stack));
    new->node = node;
    new->next = s;
    s = new;
    return s;
}


struct Stack* pop(struct Stack* s) {
    if (s == NULL) {
        return NULL;
    }

    struct TreeNode *n = s->node;

    struct Stack *tmp = s;
    s = s->next;

    free(tmp);
    return s;
}


struct TreeNode* last(struct Stack* s) {
    if (s == NULL) {
        return NULL;
    }

    return s->node;
}


int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }

    struct TreeNode* curr = NULL;
    curr = root;

    int indx = 1;
    int *result = (int*) malloc(sizeof(int) * indx);

    struct Stack* s = NULL;
    s = push(s, root);

    struct Stack* s_r = NULL;
    while (s != NULL) {
        curr = last(s);
        s = pop(s);

        s_r = push(s_r, curr);
        if (curr->left != NULL) {
            s = push(s, curr->left);
        } 

        if (curr->right != NULL) {
            s = push(s, curr->right);
        }

        while (s_r != NULL) {
            struct TreeNode* tmp = last(s_r);
            result[indx - 1] = tmp->val;
            s_r = pop(s_r);
            ++indx;
        }
    }

    *returnSize = indx - 1;

    return result;
}


struct TreeNode* insert(int val) {
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->left = NULL;
    node->right = NULL; 
    node->val = val;

    return node;
}


int main() {
    struct TreeNode* tree = NULL;
    tree = insert(1);
    tree->right = insert(2);
    tree->right->left = insert(3);

    int x;

    postorderTraversal(tree, &x);

    return 0;
}