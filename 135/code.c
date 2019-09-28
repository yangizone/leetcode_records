

int candy(int* ratings, int ratingsSize){
    int *candyNum = (int *)malloc(sizeof(int) * ratingsSize);
    int i;
    for (i = 0; i < ratingsSize;i++){
        candyNum[i] = 1;
    }
    for (i = 0; i < ratingsSize - 1; i++)
    {
        if(ratings[i]<ratings[i+1]){
            candyNum[i+1]=(candyNum[i+1]>candyNum[i])?candyNum[i+1]:candyNum[i]+1;
        }
    }
    for (i = ratingsSize-1; i >0; i--)
    {
        if(ratings[i]<ratings[i-1]){
            candyNum[i-1]=(candyNum[i-1]>candyNum[i])?candyNum[i-1]:candyNum[i]+1;
        }
    }
    int sum = 0;
    for (i = 0; i < ratingsSize;i++){
        sum += candyNum[i];
    }
    return sum;
}