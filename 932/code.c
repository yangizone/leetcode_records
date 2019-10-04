

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* beautifulArray(int N, int* returnSize){
    //看题解明思路：   
    //漂亮数组有以下的性质:
    //（1）A是一个漂亮数组，如果对A中所有元素添加一个常数，那么A还是一个漂亮数组。
    //（2）A是一个漂亮数组，如果对A中所有元素乘以一个常数，那么A还是一个漂亮数组。
    //（3）A是一个漂亮数组，如果删除一些A中所有元素，那么A还是一个漂亮数组。
    //（4) A是一个奇数构成的漂亮数组，B是一个偶数构成的漂亮数组，那么A+B也是一个漂亮数组

    //因此可以找到2^n个数的漂亮数组，删除N+1~2^n的数即可
    int *res = (int *)malloc(sizeof(int) * (N + 1)); //存储2^n个数
    int *result = (int *)malloc(sizeof(int) * N);
    //传入的参数不需要动态分配内存，否则会出错
    //returnSize = (int *)malloc(sizeof(int));
    if(N==1){
        *result = 1;
    }
    else{
        int num = (N + 1) / 2;
        int *res_temp = (int *)malloc(sizeof(int) * num);
        res_temp = beautifulArray(num, returnSize);
        int i;
        for (i = 0; i < num;i++){
            res[i] = 2 * res_temp[i] - 1;
        }
        for (i = 0; i < num;i++){
            res[num + i] = 2 * res_temp[i];
        }
        if(N<2*num){
            //删掉不需要的数
            int j = 0;
            for (i = 0; i < 2 * num; i++)
            {
                if(res[i]>N){
                    continue;
                }
                else
                {
                    result[j++] = res[i];
                }               
            }           
        }
        else
        {
            int i;
            for (i = 0; i < N; i++)
            {
                result[i] = res[i];              
            } 
        }
        
    }
    *returnSize = N;
    return result;
}
