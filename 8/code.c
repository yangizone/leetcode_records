#include<limits.h>
int myAtoi(char * str){
    int result = 0;
    int i = 0;
    char sign='+';
    while(str[i]==' '){
        i++;
    }
    if(str[i]=='\0'){
        return 0;
    }
    if(str[i]=='-'||str[i]=='+'){
        sign = str[i];
        i++;
    }
    if(!isdigit(str[i])){
        return 0;
    }
    int div = INT_MAX / 10;
    while(isdigit(str[i])){
        int dig = str[i] - '0';
        //这里均为正整数，正整数最大为2^31-1
        //负值可为-2^31，但是当其为最小数时，
        //其绝对值已越上界，直接判断返回最小值可达一样效果
        if (result < div || (result == div && dig < 8)) {
            result = result * 10 + dig;
            str++;
        }
        else
        {
            return (sign == '+') ? INT_MAX : INT_MIN;
        }     
    }
    return (sign == '+') ? result : (-result);
}