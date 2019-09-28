//暴力破解
//200 / 202 个通过测试用例 超出时间限制
int maxSubArray(int* nums, int numsSize){
    int i,j,k;
    int total_max = -INT_MAX; //可能为负数选取nums[0]
    for (i = 0; i < numsSize;i++){
        for (j = i; j < numsSize;j++){
            int total_max_temp = 0;
            for (k = i; k <= j;k++){
                total_max_temp += nums[k];
            }
            if(total_max_temp>total_max){
                total_max = total_max_temp;
            }
        }
    }
    return total_max;
}