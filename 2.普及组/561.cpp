/*************************************************************************
	> File Name: 561.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  4/29 19:21:28 2020
 ************************************************************************/

#include<iostream>
#include <cstring>
using namespace std;

#define MAX_N 10000
#define MAX_M 500

int e, f, n, w[MAX_M + 5], v[MAX_M + 5], dp[MAX_N + 5];

int main() {
    memset(dp, 0x3F, sizeof(dp));
    dp[0] = 0;
    cin >> e >> f >> n;
    f -= e;

    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = w[i]; j <= f; j++) {
            dp[j] = min(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    
    if (dp[f] == 0x3F3F3F3F) {
        cout << "This is impossible." << endl;
    } else {
        cout << "The minimum amount of money in the piggy-bank is " << dp[f] << "." << endl;
    }

    return 0;
}
