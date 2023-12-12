#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val; 
    struct TreeNode *left;
    struct TreeNode *right;
};



int minDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 10000);
    int front = 0, rear = 0, depth = 1;
    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;
        for (int i = 0; i < levelSize; ++i) {
            struct TreeNode* current = queue[front++];

            if (current->left == NULL && current->right == NULL) {
                free(queue);
                return depth;
            }

            if (current->left != NULL) {
                queue[rear++] = current->left;
            }
            if (current->right != NULL) {
                queue[rear++] = current->right;
            }
        }
        ++depth;
    }

    free(queue);
    return -1; 
}


struct TreeNode* add(int val) {
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->left = NULL;
    node->right = NULL;
    node->val = val;

    return node;
}


int main() {
    struct TreeNode *tree = NULL;
    tree = add(0);
    tree->left = add(1);
    tree->left->left = add(2);
    tree->left->left->left = add(3);

    printf_s("%d", minDepth(tree));

    return 0;
}