#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct Stack
{
    struct TreeNode* tree_node;
    struct Stack* next;
};


struct Stack* push(struct Stack* s, struct TreeNode* node) {
    struct Stack *el = (struct Stack*) malloc(sizeof(struct Stack));
    el->tree_node = node; 
    el->next = NULL;
    
    if (s == NULL) {
        return el;
    }

    struct Stack* current = s;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = el;
    return s;
}

struct Stack* pop(struct Stack* s) {
    if (s == NULL) {
        return NULL;
    }

    if (s->next == NULL) {
        free(s);
        return NULL;
    }

    struct Stack* curr = s;
    struct Stack* prev = NULL;

    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }

    free(curr); 
    if (prev != NULL) {
        prev->next = NULL;
    }

    return s; 
}


struct TreeNode* last(struct Stack* s) {
    if (s == NULL) {
        return NULL;
    }

    struct Stack* c = s;
    while (c->next != NULL) {
        c = c->next;
    }

    return c->tree_node;
}


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        return NULL;
    }

    int indx = 1; 
    returnSize = (int*) malloc(indx * sizeof(int));

    struct TreeNode *current = NULL; 
    current = root; 

    struct Stack* stack = NULL;
    while (current != NULL || stack != NULL) {
        while (current != NULL) {
            stack = push(stack, current);
            current = current->left;
        }
        current = last(stack);
        stack = pop(stack);
        
        returnSize[indx - 1] = current->val;
        ++indx;
        returnSize = (int*) realloc(returnSize, indx * sizeof(int));

        current = current->right;
    }

    return returnSize;
}


struct TreeNode* insert(struct TreeNode* node, int data) {
    if (node == NULL) {
        struct TreeNode* tree = (struct TreeNode*) malloc(sizeof(struct TreeNode));
        tree->val = data; 
        tree->left = NULL;
        tree->right = NULL;
        return tree;
    }

    if (data < node->val) {
        node->left = insert(node->left, data);
    } else if (data > node->val) {
        node->right = insert(node->right, data);
    }

    return node;
}


struct TreeNode* print(struct TreeNode* node) {
    if (node != NULL) {
        print(node->left);
        printf("%d ", node->val);
        print(node->right);
    }
}


int main() {
    struct TreeNode* tree = NULL;
    tree = insert(tree, 1);
    //tree = insert(tree, 0);
    //tree = insert(tree, 3);

    print(tree);

    int *n = inorderTraversal(tree, NULL);

    return 0;
}