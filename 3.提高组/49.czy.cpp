/*************************************************************************
	> File Name: 49.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  5/21 16:45:04 2020
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_V 100000
int dp[MAX_V + 5];

int main() {
    int V, n, v, w, s;
    cin >> V >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v >> w >> s;
        for (int k = 1; s > 0; s -= k, k *= 2) {
            k = min(k, s);/*处理最后一个二进制拆分的*/
            for (int j = V; j >= k * v; j--) {
                dp[j] = max(dp[j], dp[j - k * v] + k * w);
            }
        }
    }
    cout << dp[V] << endl;
    return 0;
}
