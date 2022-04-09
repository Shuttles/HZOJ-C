/*************************************************************************
	> File Name: 52.czy.2.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2022年03月31日 星期四 12时07分54秒
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
#include <cstring>
#include <vector>
#include <cinttypes>
using namespace std;

//dp[i] 打印前i个字符的最小磨损值
//dp[i] = min(dp[j] + price(j + 1, i))  |  j < i
//dp[i] initial = price(i, i)
#define MAX_N 1000000
int n, m;
int c[MAX_N + 5];
long long dp[MAX_N + 5];

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    return ;
}

long long price(int l, int r) {
    long long ans = 0;
    for (int i = l; i <= r; i++) {
        ans += c[i];
    }
    return (ans * ans + m);
}

long long resolve() {
    for (int i = 1; i <= n; i++) {
        dp[i] = price(1, i);
        for (int j = 1; j < i; j++) {
            dp[i] = min(dp[i], dp[j] + price(j + 1, i));
        }
    }
    return dp[n];
}

int main() {
    input();
    cout << resolve() << endl;
    return 0;
}
