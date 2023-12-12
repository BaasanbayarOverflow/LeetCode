#include <stdio.h>
#include <stdlib.h>


// Optimal Solution
/*
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int* ans = (int*)malloc(sizeof(int)*1000);
    int pos = 0;
    bool visited[1001] = {false};
    for(int i = 0 ; i < nums1Size ; i++){
        visited[nums1[i]] = true;
    }
    for(int i = 0 ; i < nums2Size ; i++){
        if(visited[nums2[i]]){
            ans[pos++] = nums2[i];
            visited[nums2[i]] = false;
        }
    }
    *returnSize = pos;
    return ans;
}
*/



int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *arr = (int*) malloc((nums1Size + nums2Size) * sizeof(int));

    int inx = 0;
    for (int i = 0; i < nums1Size; ++i) {
        for (int j = 0; j < nums2Size; ++j) {
            if (inx == 0) {
                if (nums1[i] == nums2[j]) {
                    arr[inx] = nums1[i];
                    ++inx;
                }
            } else if (inx > 0 && nums1[i] == nums2[j]) {
                int flag = 1;
                for (int k = 0; k < inx; ++k) {
                    if (nums1[i] == arr[k]) {
                        flag = 0;
                    }
                }

                if (flag) {
                    arr[inx] = nums1[i];
                    ++inx;
                }
            }
        }
    }

    return arr;
}


int main() {
    int n_1[] = {1};
    int s_1 = 1;

    int n_2[] = {2};
    int s_2 = 1;

    int p = 0;
    intersection(n_1, s_1, n_2, s_2, &p);

    return 0;
}