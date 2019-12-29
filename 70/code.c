int dp(int *result, int pos, int n){
    if(pos>n){
        return 0;
    }
    if(result[pos]!=0){
        return result[pos];
    }
    if(pos==n){
        result[pos] = 1;
        return result[pos];
    }
    result[pos] = dp(result, pos + 1, n) + dp(result, pos + 2, n);
    return result[pos];
}
int climbStairs(int n){
    if(n==0){
        return 1;
    }
    int *result = (int **)malloc(sizeof(int) * (n + 1));
    memset(result, 0, sizeof(int) * (n + 1));
    int ways = dp(result, 0, n);
    free(result);
    return ways;
}