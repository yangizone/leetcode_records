

bool isPalindrome(int x){
    if(x<0){
        return false;
    }
    // int result = 0;
    // int newx = x;
    // while(newx){
    //     int temp;
    //     temp = newx % 10;
    //     newx /= 10;
    //     //倒过来存储可能会超过int类型如2147483647
    //     result = result * 10 + temp;
    // }
    // if(result==x){
    //     return true;
    // }
    // else
    // {
    //     return false;
    // }

    int x_bit[10] = {0}; //存储整数的每个位
    int i = 0;
    while(x){
        x_bit[i] = x % 10;
        x /= 10;
        i++;
    }
    int j;
    for (j = 0; j < i / 2;j++){
        if(x_bit[j]!=x_bit[i-1-j]){
            return false;
        }
    }
    return true;
}

