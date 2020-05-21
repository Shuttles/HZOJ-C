/*************************************************************************
	> File Name: 48.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  5/21 16:38:07 2020
 ************************************************************************/

//dp[i][j]表示前i件物品，背包承重为j时的最大价值
//dp[i][j] = max(dp[i - 1][j], dp[i][j - v] + w);
#include<iostream>
using namespace std;

#define MAX_V 10000

int dp[MAX_V + 5];

int main() {
    int N, V, c, w;
    cin >> N >> V;
    for (int i = 1; i <= N; i++) {
        cin >> c >> w;
        for (int j = c; j <= V; j++) {
            dp[j] = max(dp[j], dp[j - c] + w);
        }
    }
    cout << dp[V] << endl;
    return 0;
}
