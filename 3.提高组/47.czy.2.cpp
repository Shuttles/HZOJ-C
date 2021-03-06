/*************************************************************************
	> File Name: 47.czy.1.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年01月13日 星期三 17时58分33秒
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

//dp[i][j] 前i件物品进行选择，背包容量为j时可以获得的最大价值
//dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i])

//可以优化成只有两行数组
#define MAX_N 100
#define MAX_V 10000
int dp[2][MAX_V + 5];

int main() {
    int n, V;
    cin >> V >> n;
    for (int i = 1; i <= n; i++) {
        int v, w;
        cin >> v >> w;
        for (int j = 1; j <= V; j++) {
            dp[i % 2][j] = dp[(i - 1) % 2][j];
            if (j >= v) {
                dp[i % 2][j] = max(dp[i % 2][j], dp[(i - 1) % 2][j - v] + w);
            }
        }
    }
    cout << dp[n % 2][V] << endl;
    return 0;
}
