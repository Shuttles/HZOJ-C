/*************************************************************************
	> File Name: 43.czy.2.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年01月13日 星期三 10时40分32秒
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

//dp[i][j] 从顶点走到(i, j)点所能获得的最大值
//dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + val[i][j];

#define MAX_N 1000
int val[MAX_N + 5][MAX_N + 5], dp[MAX_N + 5][MAX_N + 5];

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> val[i][j];
        }
    }

    dp[1][1] = val[1][1];

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1) {
                dp[i][j] = dp[i - 1][j] + val[i][j];
            } else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + val[i][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + val[i][j];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}
