#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    if (root == NULL) return NULL;

    int *paths = (int*) malloc(10001 * sizeof(int*));
    struct TreeNode** stack = (struct TreeNode**) malloc(10001 * sizeof(struct TreeNode*));
    int inx = 0;
    struct TreeNode* curr = root; 
    struct TreeNode* prev = NULL;

    while (1) {
        while (curr) {
            stack[inx] = curr; 
            paths[inx] = curr->val;
            curr = curr->left;
            ++inx;
        }

        curr = stack[--inx];

        if (curr->right && curr->right != prev) {
            curr = curr->right;
        } else {
            if (!curr->right && !curr->left) {
                printf("%d ", paths[0]);
            } 
        }
    }

}