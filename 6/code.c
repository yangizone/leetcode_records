char * convert(char * s, int numRows){
    //找规律发现第一行为%(2*(numRows-1))==0
    //         第二行为%(2*(numRows-1))==1 -1
    //以此类推
    //考虑numRows==1的情况
    if(numRows==1){
        return s;
    }
    char **result=(char **)malloc(sizeof(char *)*numRows);
    int i;
    for (i = 0; i < numRows;i++){
        result[i] = (char *)malloc(sizeof(char) * 1000);
    }
    int *len = (int *)malloc(sizeof(int) * numRows);
    memset(len, 0, sizeof(int) * numRows);
    i = 0;
    while(s[i]!='\0'){
        int index = i % (2 * (numRows - 1));
        if(index>=numRows){
            index = 2 * (numRows - 1) - index;
        }
        result[index][len[index]] = s[i];
        len[index]++;
        i++;
    }

    // for (i = 0; i < numRows;i++){
    //     int j;
    //     for (j = 0; j < len[i];j++){
    //         printf("%c",result[i][j]);
    //     }
    // }
    //要考虑最后一位是'\0'
    char *newString = (char *)malloc(sizeof(char) * (i + 1));
    int k = 0;
    for (i = 0; i < numRows;i++){
        int j;
        for (j = 0; j < len[i];j++){
            newString[k] = result[i][j];
            k++;
        }
    }
    newString[k] = '\0';
    //printf("%s",newString);
    return newString;
}