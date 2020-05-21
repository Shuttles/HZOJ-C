/*************************************************************************
	> File Name: 47.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  5/21 16:13:45 2020
 ************************************************************************/

//dp[i][j]表示，前i件物品可选，背包承重为j时的最大价值
//dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v] + w)
#include<iostream>
using namespace std;
#define MAX_V 10000
#define MAX_N 100

int dp[MAX_V + 5];


int main() {
    int V, n, v, w;
    cin >> V >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v >> w;
        for (int j = V; j >= v; j--) {
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    cout << dp[V] << endl;
    return 0;
}
