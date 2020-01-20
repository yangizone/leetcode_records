struct hash_entry {
    char id[1]; //只有int,char[]等类型的key //char id; //存储字符
    int value; //存储字符对应的数值
    UT_hash_handle hh;
};

struct hash_entry *users = NULL;

char RomanChar[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int RomanInt[] = {1, 5, 10, 50, 100, 500, 1000};

int romanToInt(char * s){
    //保存当前的字符串，当碰到下一个字符串是可以连成的就相减不能的就相加
    //可以尝试一下用Hash表存储字符串对应的数值，也可以增加熟练度
    int i;
    for (i = 0; i < 7;i++){
        //因为已经确定不重复就不做判断了
        struct hash_entry *tmp = (struct hash_entry *)malloc(sizeof(struct hash_entry));
        char romanChar[1];
        romanChar[0] = RomanChar[i];
        strcpy(tmp->id, romanChar);
        //tmp->id = romanChar;
        tmp->value = RomanInt[i];
        HASH_ADD_STR(users, id, tmp);
    }
    //查找字符
    //struct hash_entry *tmp;
    //HASH_FIND_STR(users, *s, tmp);
    int res;
    char temp = '\0'; //存储前一个字符
    while(*s!='\0'){
        if(temp=='\0'){
            temp = *s;
        }
        else{
            struct hash_entry *tmp = NULL;
            char temp2[1];
            int temp1;
            switch (temp)
            {
                case 'I':
                    if(*s=='V' || *s=='X'){
                        temp2[0] = *s;
                        HASH_FIND_STR(users, temp2, tmp);
                        temp1 = tmp->value; //存储当前字符的数值
                        res += (temp1 - 1);
                    }
                    else {
                        temp2[0] = *s;
                        HASH_FIND_STR(users, temp2, tmp);
                        temp1 = tmp->value; //存储当前字符的数值
                        res += (temp1 + 1);
                    }
                    temp = '\0';
                    break;
                case 'X':
                    if(*s=='V' || *s=='X'){
                        temp2[0] = *s;
                        HASH_FIND_STR(users, temp2, tmp);
                        temp1 = tmp->value; //存储当前字符的数值
                        res += (temp1 - 10);
                    }
                    else {
                        temp2[0] = *s;
                        HASH_FIND_STR(users, temp2, tmp);
                        temp1 = tmp->value; //存储当前字符的数值
                        res += (temp1 + 10);
                    }
                    temp = '\0';
                    break;
                case 'C':
                    if(*s=='V' || *s=='X'){
                        temp2[0] = *s;
                        HASH_FIND_STR(users, temp2, tmp);
                        temp1 = tmp->value; //存储当前字符的数值
                        res += (temp1 - 100);
                    }
                    else {
                        temp2[0] = *s;
                        HASH_FIND_STR(users, temp2, tmp);
                        temp1 = tmp->value; //存储当前字符的数值
                        res += (temp1 + 100);
                    }
                    temp = '\0';
                    break;
                default:
                    temp2[0] = temp;
                    HASH_FIND_STR(users, temp2, tmp);
                    temp1 = tmp->value; //存储当前字符的数值
                    res += temp1;
                    temp = *s;
                    break;
            }
        }
        s++;
    }
    if(*s!='\0'){
        struct hash_entry *tmp = NULL;
        char temp2[1];
        temp2[0] = temp;
        HASH_FIND_STR(users, temp2, tmp);
        int temp1 = tmp->value; //存储当前字符的数值
        res += temp1;
    }
    return res;
}

//1、没有char类型的key，需要用string类型
//2、string类型需要用strcpy(tmp->id, romanChar)不能用tmp->id=romanChar
//3、switch中不能声明变量
//4、struct hash_entry *tmp需要先定为NULL才能使用
//5、将Key存入hash表时要为其分配内存        
//struct hash_entry *tmp = (struct hash_entry *)malloc(sizeof(struct hash_entry));