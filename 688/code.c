int directions[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {-2, -1}, {-1, -2}, {2, -1}, {1, -2}};
//跑25 100 0 0会超时 dp只用到8ms/4ms
//跑25 10 0 0 408ms dp会降到4ms
// double knightProbability(int N, int K, int r, int c){
//     if(K<0||N<=0){
//         return -1;
//     }
//     if(r<0||r>=N||c<0||c>=N){
//         return 0;
//     }
//     if(K==0){
//         return 1;
//     }
//     else{
//         double temp = 0;
//         int i;
//         for (i = 0; i < 8;i++){
//             temp += knightProbability(N, K - 1, r + directions[i][0], c + directions[i][1]);
//         }
//         return temp / 8.0;
//     }
//     //return 1;
// }

//降低时间复杂度，使用dp
//执行用时 :12 ms, 在所有 c 提交中击败了56.00%的用户
//内存消耗 :8.6 MB, 在所有 c 提交中击败了80.00%的用户
//dp[r][c][k]需要三维数组，降维！！！
//dp[(r-1)*N+c-1][k]?
double Dp(int N, int K, int r, int c, double **dp){
    if(dp[r * N + c][K]!=2.0){
        return dp[r * N + c][K];
    }
    if(K==0){
        dp[r * N + c][K] = 1.0;
        return 1.0;
    }
    else{
        double temp = 0;
        int i;
        for (i = 0; i < 8;i++){
            int tempr = r + directions[i][0];
            int tempc = c + directions[i][1];
            if(tempr<0||tempr>=N||tempc<0||tempc>=N){
                continue;
            }
            temp += Dp(N, K - 1, tempr, tempc, dp);
        }
        dp[r * N + c][K] = temp / 8.0;
        return dp[r * N + c][K];
    }
}

double knightProbability(int N, int K, int r, int c){
    if(K<0||N<=0){
        return -1;
    }
    double **dp = (double **)malloc(sizeof(double *) * N * N);
    int i;
    for (i = 0; i < N * N; i++)
    {
        dp[i] = (double *)malloc(sizeof(double) * (K + 1));
        //赋值double类型不能直接赋值-1/2这种
        //必须赋值为double型如2.0，-1.0(不行，理由未知)
        //同时用memset赋值double类型，赋值0可以赋值其他值只能用循环
        //memset(dp[i], 2.0, sizeof(double) * (K + 1));
    }
    for (i = 0; i < N * N; i++)
    {
        int j;
        for (j = 0; j <= K;j++){
            dp[i][j] = 2.0;
        }
    }
    //memset(dp, -1, sizeof(double) * N * N);
    double result = Dp(N, K, r, c, dp);
    //double result = 0;
    // for (i = 0; i < N * N; i++)
    // {
    //     int j;
    //     for (j = 0; j <= K;j++){
    //         printf("%lf ", dp[i][j]);
    //     }
    // }
    
    //释放动态分配的内存
    for (i = 0; i < N * N; i++)
    {
        free(dp[i]);
    }
    free(dp);
    return result;
}