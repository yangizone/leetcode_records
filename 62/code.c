int  dp(int **result, int x, int y, int m, int n){
    if(x>=n || y>=m){
        return 0;
    }
    if(result[x][y]!=0){
        return result[x][y];
    }
    if(x==n-1 && y==m-1){
        result[x][y] = 1;
        return result[x][y];
    }
    int downWays = dp(result, x + 1, y, m, n);
    int rightWays = dp(result, x, y + 1, m, n);
    result[x][y] = downWays + rightWays;
    return result[x][y];
}

int uniquePaths(int m, int n){
    int **result = (int **)malloc(sizeof(int *) * n);
    int i;
    for (i = 0; i < n;i++){
        result[i] = (int *)malloc(sizeof(int) * m);
    }
    //memset在初始化时对从buffer指针处开始的连续size_t个字节按字节进行初始化赋值为ch。
    //memset(result, 0, sizeof(int) * m * n);
    for (i = 0; i < n;i++){
        memset(result[i], 0, sizeof(int) * m);
    }
    int ways = dp(result, 0, 0, m, n);
    for (i = 0; i < n;i++){
        free(result[i]);
    }
    free(result);
    return ways;
}