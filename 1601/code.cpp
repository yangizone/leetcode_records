/*
思路：
1)因为n的数量比较小，考虑遍历所有请求，使用Bitmap
时间复杂度：O(2 ^ n)
空间复杂度：O(n)
*/

class Solution {
public:
    // 针对每个请求n，判断共len位，是否满足要求
    bool valids(int n, vector<vector<int>>& requests, int len) {
        int a[len];
        memset(a, 0, sizeof(a));
        for (int i = 0; i < requests.size(); i++) {
            if ((n >> i) & 1) {
                a[requests[i][0]]--;
                a[requests[i][1]]++;
            }
        }
        for (int i = 0; i < len; i++) {
            if (a[i] != 0) return false;
        }
        return true;
    }

    int bits(int n) {
        int ans = 0;
        while (n) {
            ans++;
            n &= (n - 1); // 从末位第1个1开始计数1
        }
        return ans;
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        int len = requests.size();
        int ans = 0;
        // 将每个请求判断是否满足，可状压成bitmap
        for (int i = 1; i < (1 << len); i++) {
            int tmp = bits(i);
            // 当前的请求数不足之前的，那么即可满足要求也不是最大请求数，直接下一个
            if (tmp <= ans) continue;
            // 当前请求数够大，且满足要求
            if (valids(i, requests, n)) ans = tmp;
        }
        return ans;
    }
};