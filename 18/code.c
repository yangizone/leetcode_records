/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    if(numsSize<=0){
        return NULL;
    }
    int i;
    for(i=0;i<numsSize;i++){
        int j;
        for(j=i+1;j<numsSize;j++){
            if(nums[j]<nums[i]){
                int temp=nums[j];
                nums[j]=nums[i];
                nums[i]=temp;
            }
        }
    }
    for(i=0;i<numsSize;i++){
       printf("%d ",nums[i]);
    }
    int **result=(int **)malloc(sizeof(int *) * 1000);
    for(i=0;i<1000;i++){
        result[i]=(int *)malloc(sizeof(int) * 4);
        //memset(result[i],0,sizeof(int)*4);
    }
    for(i=0;i<1000;i++){
        memset(result[i],0,sizeof(int)*4);
    }
    // for(i=0;i<1000;i++){
    //     int j;
    //     printf("%d: ", i);
    //     for (j = 0; j < 4;j++){
    //         printf("%d ", result[i][j]);
    //     }
    //     printf("\n");
    // }
    //int result[1000][4]={{0,0,0,0}};
    //memset(result,0,sizeof(int *) * 10000);
    int num=0;
    int a; //a为最左侧的指针
    for(a=0;a<numsSize-3;a++){
        int b; //b为a右侧的指针
        for(b=a+1;b<numsSize-2;b++){
            int targetInner=target-nums[a]-nums[b];
            int c,d; //c和d为在剩下区间内的两指针
            for(c=b+1,d=numsSize-1;c!=d;){
                //避免重复
                if((c!=(b+1))&&nums[c]==nums[c-1]){
                    c++;
                }
                if((d!=(numsSize-1))&&nums[d]==nums[d+1]){
                    d--;
                }
                int temp=nums[c]+nums[d];
                if(temp==targetInner){
                    result[num][0]=nums[a];
                    result[num][1]=nums[b];
                    result[num][2]=nums[c];
                    result[num][3]=nums[d];
                    num++;
                    c++;
                }
                else if(temp<targetInner){
                    c++;
                }
                else{
                    d--;
                }
            }
        }
    }

    *returnSize=num;
    *returnColumnSizes=(int *)malloc(sizeof(int)*num);
    for(i=0;i<num;i++){
        (*returnColumnSizes)[i]=4;
    }
    return result;
}