/* 统计包含给定前缀的字符串 
思路：
1)可以计算一直使用一个轮胎跑n圈所花费的时间，这里只换一次轮胎，加上去
2)通过1可以得到跑1~n圈，只使用一个轮胎所需要的最少时间
3)完成n圈比赛，花费时间为完成k圈比赛加上使用1个轮胎完成n-k圈比赛的时间
4)动态规划解决
时间复杂度：O(nm^2)
空间复杂度：O(n)
*/

void printfTime(int *a, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

typedef long long ll;
int minimumFinishTime(int** tires, int tiresSize, int* tiresColSize, int changeTime, int numLaps){
    ll a[numLaps + 1];
    ll dp[numLaps + 1];
    memset(a, 0x3f, sizeof(a));
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < tiresSize; i++) {
        ll f = tires[i][0];
        ll r = tires[i][1];
        ll t = changeTime;
        for (int j = 1; j < numLaps + 1 && a[j] > f && f < (1e9+1e5); j++) { // 这里注意要保证f * r能超过ll，r最大为1e5，可以反推f的最大值
            t += f;
            a[j] = fmin(a[j], t);
            f *= r;
        }
    }
    //printfTime(a, numLaps + 1);
    dp[0] = 0;
    for (int i = 1; i <= numLaps; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = fmin(dp[i], dp[i - j] + a[j]);
        }
    }
    //printfTime(dp, numLaps + 1);
    return (int)(dp[numLaps] - changeTime);
}