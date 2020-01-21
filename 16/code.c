//执行用时 :12 ms, 在所有 C 提交中击败了69.55%的用户
//内存消耗 :7.2 MB, 在所有 C 提交中击败了6.91%的用户
int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
int threeSumClosest(int* nums, int numsSize, int target){
    //和四数之和思想类似，更简单一点
    //双指针
    if(nums==NULL || numsSize<3){
        return 0;
    }
    int res=0;
    int diff = INT_MAX;
    //快排
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    int i;
    for (i = 0; i < numsSize - 2;i++){
        //int abs(int j)
        int head = i + 1;
        int tail = numsSize - 1;
        while(head<tail){
            int tmpTotal = nums[i] + nums[head] + nums[tail];
            if(tmpTotal<target){
                head++;
            }
            else if(tmpTotal>target){
                tail--;
            }
            else{
                return target;
            }
            res=(abs(tmpTotal-target)>diff)?res:tmpTotal;
            diff=(abs(tmpTotal-target)>diff)?diff:abs(tmpTotal-target);
        }
    }
    return res;
}