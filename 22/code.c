/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//回溯算法
//执行用时 :16 ms, 在所有 C 提交中击败了15.52%的用户
//内存消耗 :11.2 MB, 在所有 C 提交中击败了74.40%的用户
void backTrace(char** result,char* dummy,int* returnSize,int n,int left,int right){
    if(left>n||right>n){
        return;
    }
    //n>=left>=right
    if(left==right && right==n){
        //下面这个问题我已发现，是只能(*returnSize)不能缺少括号，类17.电话号码的组合
        //怀疑不能直接对两个指针赋值
        //result[*returnSize] = dummy;
        //printf("%s\n",dummy);
        memcpy(result[(*returnSize)], dummy, (2 * n + 1));
        (*returnSize)++;
        return;
    }
    if(left<n){
        dummy[left + right] = '(';
        //这里翻了一个错误:++left
        //在这一层函数里，这个left都应当是不变的。
        backTrace(result, dummy, returnSize, n, left+1, right);
    }
    if(left>right && right<n){
        dummy[left + right] = ')';
        backTrace(result, dummy, returnSize, n, left, right+1);
    }
    return;
}

char ** generateParenthesis(int n, int* returnSize){
    *returnSize = 0;
    //这个初始值判断看答案是什么输出什么，这回答案输出[""]那么就不必返回0
    // if(n==0){
    //     return 0;
    // }
    char **result = (char **)malloc(sizeof(char *) * 10000);
    int i;
    for (i = 0; i < 10000;i++){
        result[i] = (char *)malloc(sizeof(char) * (2 * n + 1));
    }
    for (i = 0; i < 10000;i++){
        memset(result[i],'\0',sizeof(char) * (2 * n + 1));
    }
    char *dummy = (char *)malloc(sizeof(char) * (2 * n + 1));
    memset(dummy,'\0',sizeof(char) * (2 * n + 1));
    backTrace(result, dummy, returnSize, n, 0, 0);
    // printf("%d\n", *returnSize); //维测
    return result;
}