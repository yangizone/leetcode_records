
//我理解只要当前数字位置和后数该位置的字母不一致，且将最大的字符转化为尽可能小的字符即可
char * breakPalindrome(char * palindrome){
    int len = strlen(palindrome);
    char *res = (char *)malloc(sizeof(char) * (len + 1));
    //memset(res, '\0', sizeof(char) * (len + 1));
    memcpy(res, palindrome, sizeof(char) * (len + 1));
    int index = 0;  //记录最大字符的位置
    char cha = palindrome[0]; //记录最大的字符
    int i;
    for (i = 0; i < len;i++){
        if(palindrome[i]>cha){
            cha = palindrome[i];
            index = i;
        }
    }
    //替换字符
    char temp = 'a';
    int flag = 1;
    while(flag){
        if(temp!=cha){
            res[index] = temp;
            flag = 0;
        }
        else{
            temp++;
        }
    }
    if(res[index]==res[len-1-index]){
        return "";
    }
    else{
        return res;
    }
}

