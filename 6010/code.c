/*
思路：
1）每辆公交车最大花费1e7，旅途趟数最大1e7，那么最大时间不超过1e15
2）二分遍历时间，分别计算当前时间下的趟数，满足要求即为一个解
时间复杂度：O(log(n))
空间复杂度：O(1)
*/

typedef long long ll;

long long minimumTime(int* time, int timeSize, int totalTrips){
    ll l = 0;
    ll r = 1e15;
    ll ret;
    while (l < r) {
        ll m = l + (r - l) / 2;
        ll tmp = 0;
        for (int i = 0; i < timeSize; i++) {
            tmp += m / time[i];
            if (tmp >= totalTrips) break;
        }
        if (tmp >= totalTrips) {
            ret = m;
            r = m; 
        } else {
            l = m + 1;
        }
    }
    return ret;
}
