/*************************************************************************
	> File Name: 44.最长上升子序列.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  4/30 19:30:31 2020
 ************************************************************************/

//dp[i] = dp[j] + 1 (if (val[j] < val[i]))
//后来发现这是不完备的，正确的状态转移方程如29行所示
//其实是我理解错了，光哥写的是dp[i] = max(dp[j]) + 1;
#include<iostream>
using namespace std;

#define MAX_N 1000000
#define INF 0x3f3f3f3f

int dp[MAX_N + 5];//以第i位作为结尾的最长子序列长度
int arr[MAX_N + 5], len[MAX_N + 5], sum;//len[i]为长度为i的子序列的尾部最小值

int bs(int *arr, int l, int r, int x) {
    /*找到第一个大于等于x的位置*/
    if (l == r) return l; 
    int mid = (l + r) >> 1;
    if (arr[mid] < x) return bs(arr,  mid + 1, r, x);
    return bs(arr, l, mid, x);
}

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i] = 1;
        len[i] = INF;
    }

    len[++sum] = arr[1];

    for (int i = 2; i <= n; i++) {
        dp[i] = bs(len, 1, sum + 1, arr[i]);
        len[dp[i]] = arr[i];
        sum = max(dp[i], sum);
    }
    cout << sum << endl;
    return 0;
}
