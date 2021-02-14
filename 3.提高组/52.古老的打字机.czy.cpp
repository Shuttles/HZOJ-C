/*************************************************************************
	> File Name: 52.古老的打字机.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月14日 星期日 12时13分37秒
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
#include <cinttypes>
using namespace std;



//dp[i] 打印前i个字符的最小磨损值
//dp[i] = min(dp[j] + 磨损值)
#define MAX_N 1000000
#define S(a) ((a) * (a))
long long dp[MAX_N + 5], c[MAX_N + 5];
int M, n;

long long loss(int start, int end, int M) {
    long long ans = 0;
    for (int i = start; i <= end; i++) {
        ans += c[i];
    }
    ans = S(ans) + M;
    return ans;
}

void input() {
    cin >> n >> M;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
}

long long solve() {
    dp[1] = S(c[1]) + M;
    for (int i = 2; i <= n; i++) {
        //dp[i] = INT32_MAX;
        dp[i] = loss(1, i, M);//初始值必须是这个！代表了打字机只连续打印一次！
        for (int j = 1; j < i; j++) {
            dp[i] = min(dp[i], dp[j] + loss(j + 1, i, M));
        }
    }
    return dp[n];
}

int main() {
    input();
    cout << solve() << endl;
    return 0;
}
