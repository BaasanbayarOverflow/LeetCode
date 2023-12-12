#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;


struct TreeNode {
    int val; 
    struct TreeNode *left;
    struct TreeNode *right;
};


bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    if (left == NULL && right == NULL) {
        return true;
    }

    if (left == NULL || right == NULL) {
        return false;
    }
    
    return ((left->val == right->val) && (isMirror(left->left, right->right)) && (isMirror(left->right, right->left)));
}


bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }

    return isMirror(root->left, root->right);
}


struct TreeNode* insert(struct TreeNode *tree, int val) {
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


void print(struct TreeNode* tree) {
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

    printf_s("%d", isSymmetric(tree));

    return 0;
}