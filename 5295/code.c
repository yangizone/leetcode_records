/*
    给你一个整数 n，请你返回任意一个由 n 个各不相同的整数组成的数组，
    并且这 n 个数相加和为 0 。

    示例 1：
    输入：n = 5
    输出：[-7,-1,1,3,4]
    解释：这些数组也是正确的 [-5,-1,1,2,3]，[-3,-1,2,-2,4]。

    示例 2：
    输入：n = 3
    输出：[-1,0,1]

    示例 3：
    输入：n = 1
    输出：[0]

    提示：1 <= n <= 1000
*/



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize){
    *returnSize = n;
    int *result = (int *)malloc(sizeof(int) * n);
    //对称性，奇数则加上0
    int temp = n / 2;
    int i;
    for (i = 0; i < temp;i++){
        result[2 * i] = i + 1;
        result[2 * i + 1] = -(i + 1);
    }
    if(n>2*temp){
        result[n - 1] = 0;
    }
    return result;
}
