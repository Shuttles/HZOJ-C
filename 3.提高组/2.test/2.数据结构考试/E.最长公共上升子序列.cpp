/*************************************************************************
	> File Name: E.最长公共上升子序列.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  5/30 16:35:16 2020
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cinttypes>
using namespace std;



#define MAX_N 3000
int  a[MAX_N + 5], b[MAX_N + 5];
int64_t dp[MAX_N + 5][MAX_N + 5];

int main() {
    int n;
    int64_t sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    for (int i = 0; i < n; i++) {
        if (a[i] == b[0]) dp[i][0] = 1;
        else dp[i][0] = 0;

        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i][j - 1];
            if (a[i] - b[j]) continue;
            dp[i][j] = max(dp[i][j], 1LL);
            for (int k = 0; k < i; k++) {
                if (a[k] < a[i]) dp[i][j] = max(dp[i][j], dp[k][j - 1] + 1);
            }
            sum = max(sum, dp[i][j]);
        }
    }
    cout << sum << endl;
    return 0;
}
