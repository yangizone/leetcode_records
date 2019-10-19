int calLen(int* p1, int* p2){
    int x = p1[0] - p2[0];
    int y = p1[1] - p2[1];
    return x * x + y * y;
}

bool isSame(int* p1, int* p2){
    if(p1[0]==p2[0]&&p1[1]==p2[1]){
        return true;
    }
    return false;
}

bool validSquare(int* p1, int p1Size, int* p2, int p2Size, int* p3, int p3Size, int* p4, int p4Size){
    //各点不能重复
    if(isSame(p1,p2)||isSame(p1,p3)||isSame(p1,p4)||isSame(p2,p3)||isSame(p2,p4)||isSame(p3,p4)){
        return false;
    }
    //正方形：四条边相等，另两条边相等
    int len[6]; //存储六条边长度
    len[0] = calLen(p1, p2);
    len[1] = calLen(p1, p3);
    len[2] = calLen(p1, p4);
    len[3] = calLen(p2, p3);
    len[4] = calLen(p2, p4);
    len[5] = calLen(p3, p4);

    //对六条边进行冒泡排序
    int i, j;
    for (i = 0; i < 6;i++){
        for (j = 0; j < 5-i;j++){
            if(len[j]>len[j+1]){
                int temp = len[j];
                len[j] = len[j + 1];
                len[j + 1] = temp;
            }
        }
    }

    if (len[0] == len[1] && len[1] == len[2] && len[2] == len[3] && len[4] == len[5])
        {
            return true;
        }
        else{
        return false;
    }
}