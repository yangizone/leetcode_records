/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
    *三个库函数
    *islower() / isdigit()
    *strlen()
    *void * memcpy(void *dst, void *src, int length);
 */

//回溯算法
#include <string.h>

void backTrace(char *S, int* returnSize, char **result,char *dummy, int index, int len){
    if(index==len){
        //result[*returnSize] = dummy;
        memcpy(result[*returnSize], dummy, sizeof(char) * (len + 1));
        *returnSize++;
        return;
    }
    if(isdigit(S)){
        dummy[index]=
    }
    return;
}

char ** letterCasePermutation(char * S, int* returnSize){
    *returnSize = 0;
    int len = strlen(S); //字符串长度
    char **result = (char **)malloc(sizeof(char *) * 5000);
    int i;
    for (i = 0; i < 5000;i++){
        result[i] = (char *)malloc(sizeof(char) * (len + 1));
    }
    char *dummy = (char *)malloc(sizeof(char) * (len + 1)); //存放当前满足要求的字符串
    memset(dummy, '\0', sizeof(char) * (len + 1));
    int index = 0;
    backTrace(S, returnSize, result, dummy, 0, len);
    return result;
}