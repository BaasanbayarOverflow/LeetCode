#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
   int val;
   struct TreeNode *left;
   struct TreeNode *right;
};
 

void count(struct TreeNode* root, int *counter) {
    if (root == NULL) {
        return;
    }

    (*counter)++;
    count(root->left, counter);
    count(root->right, counter);
}


int countNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int res = 0;
    count(root, &res);
    return res;
}


struct TreeNode* insert(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->left = NULL;
    node->right = NULL;
    node->val = val;
    return node;
}


int main() {
    struct TreeNode* tree = NULL;
    tree = insert(0);
    tree->left = insert(1);
    tree->right = insert(4);
    tree->left->left = insert(2);

    printf("%d ", countNodes(tree));

    return 0;
}