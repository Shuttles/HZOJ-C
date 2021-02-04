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

//可以优化成一维数组
//注意：状态定义并没有改变！！！
//
//二进制优化！！在38行！
#define MAX_N 100
#define MAX_V 100000
int dp[MAX_V + 5];

int main() {
    int n, V;
    cin >> V >> n;
    for (int i = 1; i <= n; i++) {
        int v, w, s;
        cin >> v >> w >> s;
        for (int k = 1; s > 0; k *= 2) {//k代表这一部分到底包含几个这种物品
            if (s < k) k = s;
            s -= k;
            int real_w = k * w, real_v = k * v;
            for (int j = V; j >= real_v; j--) {
                dp[j] = max(dp[j], dp[j - real_v] + real_w);
            }
        }
    }
    cout << dp[V] << endl;
    return 0;
}
