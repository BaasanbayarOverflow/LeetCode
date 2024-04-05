int max(int x, int y) {
    return (x > y) ? x : y;
}

int min(int x, int y) {
    return (x < y) ? x : y;
}


int** imageSmoother(int** img, int imgSize, int* imgColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0; 
    *returnColumnSizes = (int*) malloc(imgSize * sizeof(int));
   
    int **result = (int**) malloc(imgSize * sizeof(int*));
    for (int i = 0; i < imgSize; ++i) {
        int *row = (int*) malloc(*imgColSize * sizeof(int));
        for (int j = 0; j < *imgColSize; ++j) {
            int top = max(0, i - 1);
            int bottom = min(imgSize, i + 2);
            int left = max(0, j - 1);
            int right = min(*imgColSize, j + 2);

            int div = 0;  
            int total = 0;  
            for (int k = top; k < bottom; ++k) {
                for (int z = left; z < right; ++z) {
                    total += img[k][z];
                    ++div;
                }
            }

            row[j] = total / div;
        }
        result[i] = row;
        ++(*returnSize);
        (*returnColumnSizes)[i] = *imgColSize;
    }

    return result;
}