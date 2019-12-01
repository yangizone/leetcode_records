/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    //Line 240: Char 15: runtime error: load of null pointer of type 'int *' (__Serializer__.c)
    //[]
    //0
    if(numsSize <= 0 || nums == NULL){
        //当返回空时要注意要将*returnSize赋值为0
        *returnSize = 0;
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
    // for(i=0;i<numsSize;i++){
    //    printf("%d ",nums[i]);
    // }
    int **result=(int **)malloc(sizeof(int *) * 1000);
    for(i=0;i<1000;i++){
        result[i]=(int *)malloc(sizeof(int) * 4);
        //memset(result[i],0,sizeof(int)*4);
    }
    // for(i=0;i<1000;i++){
    //     memset(result[i],0,sizeof(int)*4);
    // }
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
        //这里也需要考虑重复的情况
        //又出一样的问题：别忘了continue!!!
        if((a!=0)&&nums[a]==nums[a-1]){
            continue;
        }       
        int b; //b为a右侧的指针
        for(b=a+1;b<numsSize-2;b++){
            //又查询了continue的用法，结束当前循环但还会执行i++!!!
            //这里也需要考虑重复的情况
            if((b!=(a+1))&&nums[b]==nums[b-1]){
                continue;
            }   
            int targetInner=target-nums[a]-nums[b];
            int c,d; //c和d为在剩下区间内的两指针
            for(c=b+1,d=numsSize-1;c<d;){
                //之前用c!=d错误用c<d正确理由是因为
                //我在下面的判断中对于相同的直接加一没有跳出当前循环，因此可能导致c+2/d-2的情况导致循环一直持续下去
                //避免重复
                // if((c!=(b+1))&&nums[c]==nums[c-1]){
                //     c++;
                // }
                // if((d!=(numsSize-1))&&nums[d]==nums[d+1]){
                //     d--;
                // }
                if((c!=(b+1))&&nums[c]==nums[c-1]){
                    c++;
                    continue;
                }
                if((d!=(numsSize-1))&&nums[d]==nums[d+1]){
                    d--;
                    continue;
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
    // for(i=0;i<1;i++){
    //     int j;
    //     printf("\n%d: ", i);
    //     for (j = 0; j < 4;j++){
    //         printf("%d ", result[i][j]);
    //     }
    //     printf("\n");
    // }

    *returnSize=num;
    *returnColumnSizes=(int *)malloc(sizeof(int)*num);
    for(i=0;i<num;i++){
        (*returnColumnSizes)[i]=4;
    }
    return result;
}