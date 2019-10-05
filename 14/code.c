

char * longestCommonPrefix(char ** strs, int strsSize){
    //执行用时 :4 ms, 在所有 C 提交中击败了87.43%的用户
    //内存消耗 :7.3 MB, 在所有 C 提交中击败了77.27%的用户
    //前缀有限项，复杂度在O(n)，实际上我认为是接近O(n^2)
    //需要考虑输入字符串为空的情况
    if(strs==NULL||strsSize<=0){
        return "";
    }
    int i;
    char *temp = (char *)malloc(sizeof(char) * 1000);
    //未初始化结尾会出现"�"，同时只要结尾是'\0'即可
    for (i = 0; i < 1000;i++){
        temp[i] = '\0';
    }
    //返回空字符串最后一位为'\0'
    int j = 0;
    char tempChar;
    bool flag = true;
    while(flag){
        for (i = 0; i < strsSize;i++){
            if(strs[i][j]!='\0'){
                if(i==0){
                    tempChar = strs[i][j];
                }
                else{
                    if(strs[i][j]!=tempChar){
                        flag = false;
                        break;
                    }                   
                }
            }
            else
            {
                flag = false;
                break;
            }        
        }
        if(i==strsSize){
            temp[j] = tempChar;
        }
        j++;
    }
    return temp;
}

