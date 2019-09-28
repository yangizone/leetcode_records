

int reverse(int x){
    int temp=x;
    int result[32];
    int i=0;
    int len=0;
    while(temp!=0){
        result[i]=temp%10;
        temp/=10;
        len++;
    }
    int j;
    for(j=0;j<len;j++){
        printf("%d",result[len-j]);
    }
    return 0;
}