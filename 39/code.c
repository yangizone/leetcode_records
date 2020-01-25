/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void combination(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int i, int totalNum, int *temp){
    if(totalNum>=target){
        return;
    }
    
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    int **res = (int **)malloc(sizeof(int) * 1000);
    int i;
    for (i = 0; i < 100;i++){
        res[i] = (int *)malloc(sizeof(int) * 1000);
        memset(res[i], '\0', sizeof(int) * 1000);
    }
    int *temp = (int *)malloc(sizeof(int) * 1000);
    memset(res[i], '\0', sizeof(int) * 1000);
    combination(candidates, candidatesSize, target, returnSize, returnColumnSizes, 0, 0, temp);
    return res;
}