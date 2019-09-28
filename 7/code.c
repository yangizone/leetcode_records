

int reverse(int x){
    //只能存下32位的有符号整数，数值范围在[-2^31,2^31-1]
    //如下会报1534236469  (result * 10 + temp[j])非Int型，不知道为什么
    // if((result * 10 + temp[j])>INT_MAX||(result * 10 + temp[j])<INT_MIN){
    //     return 0;
    // }
    int result = 0;
    int temp = x;
    while(temp){
        int ca;
        ca = temp % 10;
        temp /= 10;
        if(result>INT_MAX/10||(result==INT_MAX/10&&ca>7)){
            return 0;
        }
        if(result<INT_MIN/10||(result==INT_MIN/10&&ca<-8)){
            return 0;
        }
        result = result * 10 + ca;
    }
    return result;
}
