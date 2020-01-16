//int superEggDrop(int K, int N){
    //1 N
    //2 2 2
    //2 1 1
    //2 4 3
    //2 6 3
    //2 7 4
    //3 14 4
    //#2 3 2
    //2 9 4
    //3 25 5
    // if(K<=0){
    //     return -1;
    // }
    // if(K==1){
    //     return N;
    // }
    // if(N==1||N==2){
    //     return N;
    // }
    //这里就是从N/2开始扔即6层和7层均从3层开始扔，这就需要考虑N/2-1大于0的情况即(2,3)此时若仍按之前逻辑从1层扔需要花费3次
    //而最少思路是从2层开始扔只需要2次因此作特殊处理
    //然后经过高层迭代发现从N/2开始扔若是还包含当前层，那么后者是比前者的层要多得多，是远达不到最小次数要求的，舍弃！
    // int temp1=superEggDrop(K-1, N/2-1);
    // int temp2=superEggDrop(K, (N+1)/2); //若鸡蛋不碎当前楼层也在F范围内只是不用测该层形同0层
    // int result=((temp1>temp2)?temp1:temp2)+1;
    // return result;

    //由(2,3,2)引发思考若是从(N+1)/2层开始扔会有什么差异
    // int temp1=superEggDrop(K-1, (N-1)/2);
    // int temp2=superEggDrop(K, N/2); //若鸡蛋不碎当前楼层也在F范围内只是不用测该层形同0层 //(N+1)/2~N
    // int result=((temp1>temp2)?temp1:temp2)+1;
    // return result;

    //由(2,9,4)引发思考若是从(N+1)/2层开始扔会出现(1,4,4)的情况而从4层开始扔小层数迭代和高层迭代次数相当则只需要3次
    // //考虑分别从N/2与(N+1)/2开始扔，比较两者最小值。感觉复杂度暴增
    // if(K>=2&&N==3){
    //     return 2;
    // }
    // int temp1=superEggDrop(K-1, N/2-1);
    // int temp2=superEggDrop(K, (N+1)/2); //若鸡蛋不碎当前楼层也在F范围内只是不用测该层形同0层
    // int result1=((temp1>temp2)?temp1:temp2);
    // temp1=superEggDrop(K-1, (N-1)/2);
    // temp2=superEggDrop(K, N/2); //若鸡蛋不碎当前楼层也在F范围内只是不用测该层形同0层 //(N+1)/2~N
    // int result2=((temp1>temp2)?temp1:temp2);
    // int result=((result1<result2)?result1:result2)+1;
    // return result;

    //由(3,25,5)没具体计算，但之前就有个疑惑当K=1时次数会线性增长，而本来二分会以Log2增长，因此当划分到1时会造成次数的暴涨
    //因此就会有个问题当上层的二分真的会降低底层碰到K=1的次数吗
    //即当会将鸡蛋数降到1时，上层能否通过降低降到1时的楼层数来保证总体次数的减少
    //即以后面log2降低的速度分担更多的层数来均衡K=1线性增长次数，来保证整体次数的最优
    //此时就想到二分可能并不靠谱，需要遍历以及用dp来降低复杂度
//}



// dp V1.0
// #define getMin(a,b) ((a<b)?a:b)
// #define getMax(a,b) ((a>b)?a:b)

// int g_N = 0;

// int getDp(int K, int N,int *dp){
//     int pos = (K - 1) * g_N + N - 1;
//     if(dp[pos]!=0){
//         return dp[pos];
//     }
//     if(N==0){
//         return 0;
//     }
//     if(N==1){
//         dp[pos] = 1;
//         return dp[pos];
//     }
//     if(K==1){
//         dp[pos] = N;
//         return dp[pos];
//     }
//     int k = 2;
//     int dummy;
//     while(k<=K){
//         int tempPos1 = (k - 1) * g_N + N - 1;
//         if(dp[tempPos1]!=0){
//             k++;
//             continue;
//         }
//         dummy = N;
//         int i = 2;
//         while(i<=N){
//             int tempPos2 = (k - 1) * g_N + i - 1;
//             if(dp[tempPos2]!=0){
//                 i++;
//                 continue;
//             }
//             int dummy1 = 1 + getMax(getDp(k - 1, i - 1, dp), getDp(k, N - i, dp));
//             dummy = getMin(dummy, dummy1);
//             //dp[tempPos2] = dummy; //这行代码有问题，以后要排查一下
//             i++;            
//         }
//         dp[tempPos1] = dummy;
//         k++;
//     }
//     dp[pos] = dummy;
//     return dp[pos];
// }

// int superEggDrop(int K, int N){
//     //dp(K,N)= 1≤X≤N min(max(dp(K−1,X−1),dp(K,N−X)))
//     int *dp = (int *)malloc(sizeof(int) * K * N);
//     memset(dp, 0, sizeof(int) * K * N);
//     g_N = N;
//     int result = getDp(K, N, dp);
//     // int i;
//     // for (i = 0; i < K;i++){
//     //     int j;
//     //     for (j = 0; j < N;j++){
//     //         printf("%d ", dp[i * N + j]);
//     //     }
//     //     printf("\n");
//     // }
//     return result;
// }



// dp V2.0
//这个代码一个是整体输出答案错误，第二个是复杂度过高会不过还要优化
//即光是dp还不够，还需要用到二分查找
// #define getMin(a,b) ((a<b)?a:b)
// #define getMax(a,b) ((a>b)?a:b)

// int g_N = 0;

// int getDp(int K, int N,int *dp){
//     if(N==0){
//         return 0;
//     }
//     int pos = (K - 1) * g_N + N - 1;
//     if(dp[pos]!=0){
//         return dp[pos];
//     }
//     if(N==1){
//         dp[pos] = 1;
//         return dp[pos];
//     }
//     if(K==1){
//         dp[pos] = N;
//         return dp[pos];
//     }
//     int k = 2;
//     int dummy;
//     while(k<=K){
//         int tempPos1 = (k - 1) * g_N + N - 1;
//         if(dp[tempPos1]!=0){
//             k++;
//             continue;
//         }
//         dummy = N;
//         int i = 2;
//         while(i<=N){
//             int tempPos2 = (k - 1) * g_N + i - 1;
//             if(dp[tempPos2]!=0){
//                 i++;
//                 continue;
//             }
//             int dummy1 = 1 + getMax(getDp(k - 1, i - 1, dp), getDp(k, N - i, dp));
//             dummy = getMin(dummy, dummy1);
//             //dp[tempPos2] = dummy; //这行代码有问题，以后要排查一下
//             i++;            
//         }
//         dp[tempPos1] = dummy;
//         k++;
//     }
//     dp[pos] = dummy;
//     return dp[pos];
// }

// int superEggDrop(int K, int N){
//     //dp(K,N)= 1≤X≤N min(max(dp(K−1,X−1),dp(K,N−X)))
//     int *dp = (int *)malloc(sizeof(int) * K * N);
//     memset(dp, 0, sizeof(int) * K * N);
//     g_N = N;
//     int result = getDp(K, N, dp);
//     free(dp);
//     return result;
// }



//未参考之前思路，依旧是dp
//F(K,N)=min(1<=n<=Nmax(F(K,n-1),F(K-1,N-n)))
#define getMin(x,y) ((x<y)?x:y)
#define getMax(x,y) ((x>y)?x:y)

int superEggDrop(int K, int N){
    //用例
    //1 N
    //2 2 2
    //2 1 1
    //2 4 3
    //2 6 3
    //2 7 4
    //3 14 4
    //#2 3 2
    //2 9 4
    //3 25 5
    int *resF = (int *)malloc(sizeof(int) * (K + 1));
    int i;
    for (i = 0; i <= K;i++){
        resF[i] = (int *)malloc(sizeof(int) * (N + 1));
    }
    for (i = 0; i <= K;i++){
        resF[i] = (int *)malloc(sizeof(int) * (N + 1));
    }
    
    for (i = 1; i <= K;i++){
        int j;
        for (j = 1; j <= N;j++){
            int k;
            for (k = 1; k <= j;k++){
                resF[i][j]=resF
            }
        }
    }
}