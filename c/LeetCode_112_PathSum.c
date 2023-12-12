#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

struct TreeNode {
    int val; 
    struct TreeNode *left;
    struct TreeNode *right;
};


bool sum(struct TreeNode* node, int total, bool flag, int target) {
    if (node == NULL) {
        return flag;
    }

    total += node->val;

    if (node->left == NULL && node->right == NULL) {
        if (total == target) {
            flag = true;
        }
    }

    flag = sum(node->left, total, flag, target);
    flag = sum(node->right, total, flag, target);
}


bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) {
        return false;
    }

    return sum(root, 0, false, targetSum);
}


struct TreeNode* insert(int val) {    
    struct TreeNode *node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->left = NULL;
    node->right = NULL;
    node->val = val;
    return node;
}


int main() {
    struct TreeNode *tree = NULL; 
    tree = insert(0);
    tree->left = insert(-5);
    tree->left->left = insert(4);
    tree->right = insert(-8);

    int t = -13;

    printf_s("%d", hasPathSum(tree, t));

    return 0;
}