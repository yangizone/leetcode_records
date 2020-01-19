struct hash_entry {
    char id; //存储字符
    int value; //存储字符对应的数值
    UT_hash_handle hh;
}

struct hash_entry *users = NULL;

char RomanChar[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int RomanInt[] = {1, 5, 10, 50, 100, 500, 1000};

int romanToInt(char * s){
    //保存当前的字符串，当碰到下一个字符串是可以连成的就相减不能的就相加
    //可以尝试一下用Hash表存储字符串对应的数值，也可以增加熟练度
    int i;
    for (i = 0; i < 7;i++){
        //因为已经确定不重复就不做判断了
        struct hash_entry *tmp;
        tmp->id = RomanChar[i];
        tmp->value = RomanInt[i];
        HASH_ADD_STR(users, id, tmp);
    }
    //查找字符
    //struct hash_entry *tmp;
    //HASH_FIND_STR(users, *s, tmp);
}