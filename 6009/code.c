/* 
理解：字母异位词只要保证每个字母的个数相等即可
思路：统计每个字符串中的单个字母的数量，补上每个字母的差值即可
时间复杂度：O(n)
空间复杂度：O(1)
*/

int minSteps(char * s, char * t){
    int a[26] = {0};
    int b[26] = {0};
    int lens = strlen(s);
    int lent = strlen(t);
    for (int i = 0; i < lens; i++) {
        a[s[i] - 'a']++;
    }
    for (int i = 0; i < lent; i++) {
        b[t[i] - 'a']++;
    }
    int res = 0;
    for (int i = 0; i < 26; i++) {
        res += (a[i] > b[i]) ? (a[i] - b[i]) : (b[i] - a[i]);
    }
    return res;
}