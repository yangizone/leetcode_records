

int lengthOfLongestSubstring(char * s){
    //使用动态规划思想
    //类似Leetcode53
    //当前重复，则重定位到此，否则+1，然后和之前最大值比较
    //有问题："dvdf"
    //题解中称为经典的窗口滑动中的非定长算法，这个我根据出问题的用例之前也考虑过
    //即若遇到重复的则重定位到重复字符串的下一位，不过复杂度我认为还在O(n^2)因此想寻求更高效的算法没想到啊
    //需要考虑字符串为空的情况
    if(*s=='\0'){
        return 0;
    }
    char *s_new = (char *)malloc(sizeof(char) * 1000); //存储不重复字符的最长子串
    int len = 1;
    int ans = 1;
    s_new[0] = *s++;
    //因为输入是字符串，所以要考虑最后一位是'\0'，因此不能直接判断s==NULL
    while(*s!='\0'){
        int i;
        for (i = 0; i < len;i++){
            if(*s==s_new[i]){
                break;
            }
        }
        if(i==len){
            s_new[len++] = *s;
        }
        else{
            //TLE 复杂度依旧是O(n^2)，应该是需要Hashset这种降低复杂度
            s -= (len - i - 1);
            s_new[0] = *s;
            len = 1;
        }           
        ans = (ans > len) ? ans : len;
        s++;
        //printf("%d", len);
        //printf("%c", *s);
    }
    free(s_new);
    return ans;
}