/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//回溯算法
//执行用时 :24 ms, 在所有 C 提交中击败了12.22%的用户
//内存消耗 :17.6 MB, 在所有 C 提交中击败了5.01%的用户
#define str2int(s) s-'0'
char g_phoneNumbers[8][4] = {
    { 'a', 'b', 'c' },
    { 'd', 'e', 'f' },
    { 'g', 'h', 'i' },
    { 'j', 'k', 'l' },
    { 'm', 'n', 'o' },
    { 'p', 'q', 'r', 's' },
    { 't', 'u', 'v' },
    { 'w', 'x', 'y', 'z' }
};
int g_phoneNumber[8] = { 3, 3, 3, 3, 3, 4, 3, 4 };

void letterCombinationsInner(char *digits, char **res, int* returnSize, int i, int len, char *temp){
    //printf("%d %d\n",*returnSize,i); //维测
    if(i==len){
        memcpy(res[(*returnSize)],temp,(len+1));
        (*returnSize)++; //*returnSize++;不行
        return;
    }
    int number = str2int(digits[i]) - 2;
    if (number < 0)
    {
        return;
    }
    int j;
    for(j=0;j<g_phoneNumber[number];j++){
        //*(*(res+j)+i)=g_phoneNumbers[number][j];
        //下面会导致只有当*returnSize较小时才会对前面元素赋值
        //res[(*returnSize)][i]=g_phoneNumbers[number][j];
        temp[i]=g_phoneNumbers[number][j];
        letterCombinationsInner(digits, res, returnSize, i+1, len, temp);
        //不能放在这需要到达一个字母组合尾才能加一不然中途每一次返回函数就会多加
        //(*returnSize)++; //*returnSize++;不行
    }
    return;
}

char ** letterCombinations(char * digits, int* returnSize){
    *returnSize = 0;
    int len=strlen(digits); //代表字符串长度
    if(digits==NULL || len==0){
        return 0;
    }
    char **res = (char **)malloc(sizeof(char *) * 10000);
    int i;
    for (i = 0; i < 10000;i++){
        res[i] = (char *)malloc(sizeof(char) * (len+1));
    }
    for (i = 0; i < 10000;i++){
        memset(res[i], '\0', sizeof(char) * (len+1));
    }
    char *temp = (char *)malloc(sizeof(char) * (len+1));
    memset(temp, '\0', sizeof(char) * (len+1));
    letterCombinationsInner(digits, res, returnSize, 0, len, temp);
    // 维测
    // for(i=0;i<10;i++){
    //     int j;
    //     printf("%s\n",res[i]);
    // }
    // printf("%d\n",*returnSize);
    return res;
}
