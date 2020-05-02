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

int dp[MAX_N + 5];//以第i位作为结尾的最长子序列长度
int arr[MAX_N + 5];

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (arr[j] >= arr[i]) continue;
            dp[i] = max(dp[i], dp[j] + 1);/*不能直接写dp[i] = dp[j] + 1*/
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
