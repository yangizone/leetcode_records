//执行用时 :24 ms, 在所有 C 提交中击败了83.92%的用户
//内存消耗 :9.6 MB, 在所有 C 提交中击败了40.70%的用户
int removeDuplicates(int* nums, int numsSize){
    if(nums==NULL || numsSize==0){
        return 0;
    }
    int i = 1;
    int index = 0;
    while(i<numsSize){
        if(nums[i]==nums[index]){
            i++;
            continue;
        }
        else{
            index++;
            nums[index] = nums[i];
            i++;
        }
    }
    return index + 1;
}