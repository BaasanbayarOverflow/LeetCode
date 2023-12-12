#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

struct TreeNode {
    int val; 
    struct TreeNode *left;
    struct TreeNode *right;
};


int maxDepth(struct TreeNode* tree) {
    if (tree == NULL) {
        return 0;
    }

    int l = maxDepth(tree->left);
    int r = maxDepth(tree->right);

    return 1 + ((l > r) ? l : r); 
}


bool isBalanced(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }

    int l = maxDepth(root->left);
    int r = maxDepth(root->right);

    if (abs(l - r) > 1) {
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);    
}


int main() {

    return 0;
}