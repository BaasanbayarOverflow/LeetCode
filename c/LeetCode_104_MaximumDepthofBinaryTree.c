#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

//#define max(a,b) (((a) > (b)) ? (a + 1) : (b + 1))


struct TreeNode {
    int val; 
    struct TreeNode *left;
    struct TreeNode *right;
};


int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    } 

    int l = maxDepth(root->left);
    int r = maxDepth(root->right);

    return 1 + ((l > r) ? l : r);
}


struct TreeNode* insert(struct TreeNode *tree, int val) {
    if (tree == NULL) {
        struct TreeNode *node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
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


void print(struct TreeNode *tree) {
    if (tree != NULL) {
        printf_s("%d ", tree->val);
        print(tree->left);
        print(tree->right);
    }
}


int main() {
    struct TreeNode* tree = NULL;
    tree = insert(tree, 1);
    tree = insert(tree, 2);
    tree = insert(tree, 2);
    tree = insert(tree, 5);

    printf_s("%d ", maxDepth(tree));

    return 0;
}