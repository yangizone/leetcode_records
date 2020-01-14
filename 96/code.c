//执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
//内存消耗 :6.8 MB, 在所有 C 提交中击败了5.26%的用户
int numTrees(int n){
    //我理解n个节点组成的二叉搜索树是固定个数
    //那么将每个节点的左右二叉搜索树个数相乘再相加即为总个数
    //dp思想，先将所有n个节点的二叉搜索树个数得到
    //G(n)=1<=i<=nG(i-1)*(n-i) //公式感觉和887鸡蛋掉落有点类似
    if(n<=0){
        return 1;
    }
    int *dp = (int *)malloc(sizeof(int) * (n + 1));
    memset(dp, 0, sizeof(int) * (n + 1));
    dp[0] = 1;
    //dp[1] = 1;
    int i;
    for (i = 1; i <= n;i++){
        int j;
        for (j = 1; j <= i;j++){
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}