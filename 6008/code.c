/* 统计包含给定前缀的字符串 
思路：遍历字符串数组，判断每个字符串前缀是否和pref相等即可
时间复杂度：O(n)
空间复杂度：O(1)
*/

int prefixCount(char ** words, int wordsSize, char * pref){
    int res = 0;
    int len = strlen(pref);
    for (int i = 0; i < wordsSize; i++) {
        int j = 0;
        for (; j < len; j++) {
            if (pref[j] != words[i][j]) {
                break;
            }
        }
        if (j == len) res++;
    }
    return res;
}