/*************************************************************************
	> File Name: 钱币问题.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  5/24 19:11:52 2020
 ************************************************************************/
//dp[i][j] = dp[i - 1][j] + dp[i - 1][j - v] + w
#include <iostream>
#include <cinttypes>
using namespace std;
#define MAX_M 20
#define MAX_N 10000

int64_t dp[MAX_N + 5] = {1};


int main() {
    int m, n;
    cin >> m >> n;
    int w[MAX_M] = {0};
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= m; i++) {
        for (int j = w[i]; j <= n; j++) {
            dp[j] += (dp[j - w[i]]);
        }
    }
    cout << dp[n] % 9973 << endl;
    return 0;
}
