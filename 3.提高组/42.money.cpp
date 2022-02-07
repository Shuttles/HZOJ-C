/*************************************************************************
	> File Name: 42.money.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2022年02月07日 星期一 15时51分46秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

//dp(i, j) 用前i种钱币凑j元钱，一共有多少种方法
//dp(i, j) = dp(i, j - w[i])     if used i
//         + dp(i - 1, j)       if not used i
//dp(0, j) = 0, dp(i, 0) = 1
//时间复杂度O(m * n)
//空间复杂度O(m * n)

#define MAX_N 10000
#define MAX_M 20
#define MOD 9973
int n, m;
int w[MAX_M + 5];
int dp[MAX_M + 5][MAX_N + 5];

void input() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    return ;
}

int output() {
    for (int i = 1; i <= m; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i]) {
                dp[i][j] += (dp[i][j - w[i]] % MOD);
            }
        }
    }

    return dp[m][n] % MOD;
}


int main() {
    input();
    cout << output() << endl;
    return 0;
}
