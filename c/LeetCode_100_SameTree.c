#include <stdio.h>
#include <Stdlib.h>

typedef enum {false, true} bool;


/*
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) {
        return 1;
    }

    if (p == NULL || q == NULL) {
        return 0;
    }

    return (p->val == q->val) && (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}
*/


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct Stack {
    struct TreeNode *node;
    struct Stack *next;
};


struct Stack* push(struct Stack *stack, struct TreeNode* node) {
    struct Stack* s = (struct Stack*) malloc(sizeof(struct Stack));
    s->next = stack; 
    s->node = node;
    return s;
}


struct Stack* pop(struct Stack *stack) {
    if (stack == NULL) {
        return NULL;
    }

    struct Stack *tmp = stack;
    stack = stack->next;
    free(tmp);
    return stack;
}


bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p != NULL && q != NULL) {
        bool flag = true;
        struct Stack *stack_p = (struct Stack*) malloc(sizeof(struct Stack));
        struct Stack *stack_q = (struct Stack*) malloc(sizeof(struct Stack));

        while ((p != NULL && q != NULL) || (stack_p != NULL && stack_q != NULL)) {
            while (p != NULL && q != NULL) {
                stack_p = push(stack_p, p);
                stack_q = push(stack_q, q);

                p = p->left;
                q = q->left;
            }

            if (!(p == NULL) != !(q == NULL)) {
                return false;
            }

            p = stack_p->node;
            q = stack_q->node;

            stack_p = pop(stack_p);
            stack_q = pop(stack_q);

            if (p->val != q->val) {
                return false;
            }

            p = p->right;
            q = q->right;
        }

        free(stack_p);
        free(stack_q);

        return flag;
    } else if (p == NULL && q == NULL) {
        return true;
    }
    return false;
}


struct TreeNode* insert(struct TreeNode* tree, int val) {
    if (tree == NULL) {
        struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
        node->left = NULL;
        node->right = NULL;
        node->val = val;
        return node; 
    }

    if (tree->left == NULL) {
        tree->left = insert(tree->left, val);
    } else if (tree->right == NULL) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


struct TreeNode* print(struct TreeNode* tree) {
    if (tree != NULL) {
        print(tree->left);
        printf_s("%d", tree->val);
        print(tree->right);
    }
}


int main() {
    struct TreeNode* tree_1 = NULL;
    tree_1 = insert(tree_1, 1);
    tree_1 = insert(tree_1, 2);
    tree_1 = insert(tree_1, 3);

    struct TreeNode* tree_2 = NULL;
    tree_2 = insert(tree_2, 1);
    tree_2 = insert(tree_2, 2);
    tree_2 = insert(tree_2, 3);

    printf_s("P tree: ");
    print(tree_1);
    printf_s("\n");

    printf_s("Q tree: ");
    print(tree_2);    

    printf_s("%d", isSameTree(tree_1, tree_2));

    return 0;
}