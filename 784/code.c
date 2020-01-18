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
//执行用时 :44 ms, 在所有 C 提交中击败了16.72%的用户
//内存消耗 :23.3 MB, 在所有 C 提交中击败了7.68%的用户
#include <string.h>

void backTrace(char *S, int* returnSize, char **result,char *dummy, int index, int len){
    if(index>=len){
        memcpy(result[(*returnSize)], dummy, sizeof(char) * (len + 1));
        (*returnSize)++;
        return;
    }
    if(isdigit(S[index])){
        dummy[index] = S[index];
        backTrace(S, returnSize, result, dummy, index + 1, len);
    }
    if(islower(S[index])){
        dummy[index] = S[index];
        backTrace(S, returnSize, result, dummy, index + 1, len);
        dummy[index] = S[index] - 'a' + 'A';
        backTrace(S, returnSize, result, dummy, index + 1, len);
    }
    if(isupper(S[index])){
        dummy[index] = S[index];
        backTrace(S, returnSize, result, dummy, index + 1, len);
        dummy[index] = S[index] - 'A' + 'a';
        backTrace(S, returnSize, result, dummy, index + 1, len);
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
    backTrace(S, returnSize, result, dummy, 0, len);
    return result;
}