/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//回溯算法
#include <string.h>
///int g_tracelel = 0;
void backTrace(char** result,char* dummy,int* returnSize,int n,int left,int right){
    ///g_tracelel++;
    //n>=left>=right
    if(left==right && right==n){
        dummy[left + right] = '\n';
        //怀疑不能直接对两个指针赋值
        //result[*returnSize] = dummy;
        // memcpy(result[*returnSize], dummy, (2 * n + 1));
        printf("%s", dummy);
        *returnSize++;
        //memset(dummy, 0, sizeof(2 * n + 1));
    }
    // if(right>left){
    //     return;
    // }
    if(left<n){
        dummy[left + right] = '(';
        left++;
        backTrace(result, dummy, returnSize, n, left, right);
    }
    if(left>right && right<n){
        dummy[left + right] = ')';
        right++;
        backTrace(result, dummy, returnSize, n, left, right);
    }
    return;
}

char ** generateParenthesis(int n, int* returnSize){
    *returnSize = 0;
    char **result = (char **)malloc(sizeof(char *) * 10000);
    int i;
    for (i = 0; i < 10000;i++){
        result[i] = (char *)malloc(sizeof(char) * (2 * n + 1));
    }
    char *dummy = (char *)malloc(sizeof(char) * (2 * n + 1));
    backTrace(result, dummy, returnSize, n, 0, 0);
    printf("%d\n", *returnSize);//
    ///printf("%d", g_tracelel);
    return result;
}