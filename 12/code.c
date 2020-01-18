//执行用时 :16 ms, 在所有 C 提交中击败了20.12%的用户
//内存消耗 :7.8 MB, 在所有 C 提交中击败了18.43%的用户
char *RomanChar[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
int RomanInt[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

char * intToRoman(int num){
    //这题看成分硬币即可，有5、10、100等硬币，也有4、9、400等硬币
    //只要将数从高到低依次取到最大的硬币既可
    if(num<=0){
        return "";
    }
    char *res = (char *)malloc(sizeof(char) * 100);
    int i = 12;
    int index = 0;
    while(num){
        if(num>=RomanInt[i]){
            num -= RomanInt[i];
            memcpy(res + index, RomanChar[i], sizeof(char) * strlen(RomanChar[i]));
            index += strlen(RomanChar[i]);
        }
        else{
            i--;
        }
    }
    res[index] = '\0';
    return res;
}