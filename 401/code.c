/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void getBinaryWatch(int num, int* returnSize, char **result, int *ishoursUsed, int *isminutesUsed, int usedNums, int hours, int minutes){
    //判断返回条件
    if(usedNums==num){
        //将当前亮灯的时间传入结果指针中返回

        (*returnSize)++;
        return;
    }
}

char ** readBinaryWatch(int num, int* returnSize){
    *returnSize = 0;
    //入参校验
    if(num==0){
        return 0;
    }
    int hours[] = {1, 2, 4, 8};
    int minutes[] = {1, 2, 4, 8, 16, 32};
    
    //判断当前LED是否亮着
    int *ishoursUsed = (int *)malloc(sizeof(int) * 4);
    memset(ishoursUsed, 0, sizeof(int) * 4);
    int *isminutesUsed = (int *)malloc(sizeof(int) * 6);
    memset(isminutesUsed, 0, sizeof(int) * 6);

    //初始化返回结果
    char **result = (char **)malloc(sizeof(char * 1000));
    int i;
    for (i = 0; i < 1000;i++){
        result[i] = (char *)malloc(sizeof(char) * 6);
        memset(result[i], '\0', sizeof(char) * 6);
    }
    getBinaryWatch(num, returnSize, result, ishoursUsed, isminutesUsed, 0, 0, 0);
    free(ishoursUsed);
    free(isminutesUsed);
    return result;
}