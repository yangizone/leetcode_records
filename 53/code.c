
int maxSubArray(int* nums, int numsSize){
    //暴力破解，复杂度O(n^2)
    //200 / 202 个通过测试用例 超出时间限制
    // int i,j,k;
    // int total_max = -INT_MAX; //可能为负数选取nums[0]
    // for (i = 0; i < numsSize;i++){
    //     for (j = i; j < numsSize;j++){
    //         int total_max_temp = 0;
    //         for (k = i; k <= j;k++){
    //             total_max_temp += nums[k];
    //         }
    //         if(total_max_temp>total_max){
    //             total_max = total_max_temp;
    //         }
    //     }
    // }
    // return total_max;

    //复杂度O(n)
    //首尾双指针，两指针向内移动，当找到新的左/右节点，就换成右/左节点
    //这方法不行，如-1 3 -2 -2 -2 -2 -2 -2 -2 -2- -2 -2 1 -2 -2 -2
    //暴力破解的时间过多是因为重复加的东西太多，考虑动态规划
    //前n长度的数组和前n+1的连续最大和子数组
    //1、当第n+1个数比前n个数最大和还大，那么首尾均变为当前数
    //2、若不大，则比较尾+1到当前数和与0大小，若大则尾更换为当前数，否则不变
    //这方法也不行：[8,-19,5,-4,20]，未考虑到在向右更替过程中只取右边一部份可能会达到更大和的效果
    // int total = nums[0];
    // int temp = 0;
    // int i;
    // for (i = 1; i < numsSize; i++)
    // {
    //     //nums[i]>total         //没考虑到增量
    //     //nums[i]>(tatal+temp)  //没考虑到负值过多
    //     if((nums[i]>total)&&(total+temp)<0){
    //         total = nums[i];
    //         temp = 0;
    //     }
    //     else{
    //         temp += nums[i];
    //         if(temp>0){
    //             total += temp;
    //             temp = 0;
    //         }
    //     }
    // }
    // return total;

    int total = 0; //当前相对最大和，保证子数组首对于最大和有正向增益
    int ans=nums[0]; //前一次的最大和
    int i;
    for (i = 0; i < numsSize; i++)
    {
        if(total>0){
            total += nums[i];
        }
        else
        {
            total = nums[i];
        }
        ans = (ans > total) ? ans : total;
    }
    return ans;

    //分治法，复杂度O(nlogn)
}