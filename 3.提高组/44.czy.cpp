/*************************************************************************
	> File Name: 44.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  5/19 10:58:23 2020
 ************************************************************************/
//dp[i]表示以i为结尾的字符串中最长上升子序列的长度
//dp[i] = max(dp[j]) + 1 if (arr[j] < arr[i])
//f[i]表示长度为i的子序列中末尾值最小的，则f数组一定是单调递增的！！

#include <iostream>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX_N 1000000

int dp[MAX_N + 5] = {0, 1}, arr[MAX_N + 5], f[MAX_N + 5];

int bs(int *f, int n, int x) {
    int head = 1, tail = n;
    while (head < tail) {
        //printf("卡住了！\n");
        int mid = (head + tail) >> 1;
        if (f[mid] < x) head = mid + 1;
        else tail = mid;
    }
    return head;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (i == 1) f[i] = arr[i];
        else f[i] = INF;
    }
    
    for (int i = 2; i <= n; i++) {
        int ind = bs(f, n, arr[i]);
        dp[i] = ind;
        f[ind] = arr[i];
    }

    /*找答案*/
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (f[i] == INF) {
            ans = i - 1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
