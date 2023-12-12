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


int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) {
        return 0;
    }

    struct Stack* s = NULL;
    s = push(s, root);

    int i = 1;
    int *result = (int*) malloc(i * sizeof(int));

    while (s != NULL) {
        struct TreeNode *curr = last(s);
        s = pop(s);

        result[i - 1] = curr->val;
        ++i;
        result = (int*) realloc(result, i * sizeof(int));

        if (curr->right != NULL) {
            s = push(s, curr->right);
        }

        if (curr->left != NULL) {
            s = push(s, curr->left);
        }
    }

    i -= 1;
    *returnSize = i;
    
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

    preorderTraversal(tree, 0);

    return 0;
}