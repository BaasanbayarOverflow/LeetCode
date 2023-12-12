#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val; 
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode* create(int *nums, int begin, int end) {
    if (begin > end) {
        return NULL;
    }

    int inx = (begin + end) / 2;
    
    struct TreeNode *node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->left = NULL;
    node->right = NULL;
    node->val = nums[inx];

    node->left = create(nums, begin, inx - 1);
    node->right = create(nums, inx + 1, end);

    return node;
}


struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize == 0 || nums == NULL) {
        return NULL;
    }

    return create(nums, 0, numsSize - 1);
}


int main() {

    return 0;
}