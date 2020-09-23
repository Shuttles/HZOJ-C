//dp[i][j] = dp[i - 1][j] + dp[i - 1][j - v] + w
#include <iostream>
#include <cinttypes>
using namespace std;
#define MAX_M 20
#define MAX_N 10000

int64_t dp[MAX_N + 5] = {1};
int w[MAX_M + 5] = {0};


int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= m; i++) {
        for (int j = w[i]; j <= n; j++) {
            dp[j] += (dp[j - w[i]]);
            dp[j] %= 9973;
        }
    }
    cout << dp[n] << endl;
    return 0;
}

