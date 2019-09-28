int search_binary(int *nums,int left,int right,int target){
    int result;
    if(left>right){
        return -1;
    }
    int temp = (left + right) / 2;
    if(nums[temp]==target){
        return temp;
    }
    else if(nums[temp]<target){
        if(nums[temp]>nums[right]){ //表明在左升序
            result = search_binary(nums, temp + 1, right, target);
        }
        else{
            //按照下面这个思路，是有一个前提的：nums[left]>nums[right]
            //但实际上，若是以两端为节点是不满足该要求的，因此需要两次和同一个节点对比
            // if(nums[left]>target){
            //     result = search_binary(nums, temp + 1, right, target);
            // }
            // else{
            //     result = search_binary(nums, left, temp - 1, target);
            // }
            if(nums[right]>=target){
                result = search_binary(nums, temp + 1, right, target);
            }
            else{
                result = search_binary(nums, left, temp - 1, target);
            }
        }
    }
    else{
        if(nums[temp]<nums[right]){ //表明在右升序
            result = search_binary(nums, left, temp - 1, target);
        }
        else{
            if(nums[right]>=target){
                result = search_binary(nums, temp + 1, right, target);
            }
            else{
                result = search_binary(nums, left, temp - 1, target);
            }
        }
    }
    return result;
}

int search(int* nums, int numsSize, int target){
    if(nums==NULL){
        return -1;
    }
    int *dummy = (int *)malloc(sizeof(int) * numsSize);
    dummy = nums;
    int result;
    result = search_binary(dummy, 0, numsSize - 1, target);
    return result;
}
