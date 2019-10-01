

int maxArea(int* height, int heightSize){
    //暴力破解
    //执行用时 :1256 ms, 在所有 C 提交中击败了28.75%的用户
    //内存消耗 :7.7 MB, 在所有 C 提交中击败了78.99%的用户
    // if(height==NULL||heightSize<2){
    //     return -1;
    // }
    // int *dummy = (int *)malloc(sizeof(int));
    // dummy = height;
    // int i, j;
    // int vol = 0;
    // for (i = 0; i < heightSize - 1; i++)
    // {
    //     for (j = i + 1; j < heightSize; j++)
    //     {
    //         int hin = (dummy[i] > dummy[j]) ? dummy[j] : dummy[i];
    //         int new_vol;
    //         new_vol = hin * (j - i);
    //         if(vol<new_vol){
    //             vol = new_vol;
    //         }
    //     }
    // }
    // return vol;

    //双指针
    //普通的思想：要容纳水取决于最短的线的长度，而且两线距离越长越好
    //一开始将双指针放于首尾，那么在其中一条线相同的情况下，必然保证了距离最长到最短的可能性
    //接下来需要考虑最短的长度的情况，只需要将最短的线依次向里靠近即可
    //执行用时 :20 ms, 在所有 C 提交中击败了88.82%的用户
    //内存消耗 :7.8 MB, 在所有 C 提交中击败了68.71%的用户
    if(height==NULL||heightSize<2){
        return -1;
    }
    int *dummy = (int *)malloc(sizeof(int));
    dummy = height;
    int i; //首指针
    int j; //尾指针
    int vol = 0;
    for (i = 0, j = heightSize - 1; i < j;){
        int new_vol = 0;
        if(dummy[i] > dummy[j]){
            new_vol = dummy[j] * (j - i);
            vol = (vol > new_vol) ? vol : new_vol;
            j--;
        }
        else
        {
            new_vol = dummy[i] * (j - i);
            vol = (vol > new_vol) ? vol : new_vol;
            i++;
        }
    }

    return vol;
}

