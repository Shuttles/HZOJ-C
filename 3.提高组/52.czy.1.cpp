/*************************************************************************
	> File Name: 52.czy.1.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月14日 星期日 16时19分47秒
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

#define MAX_N 1000000
#define S(a) ((a) * (a))
long long dp[MAX_N + 5];
long long c[MAX_N + 5], s[MAX_N + 5];
long long f[MAX_N + 5];//查找项
long long q[MAX_N + 5], head, tail;//斜率单调递增的单调队列
int n, M;

double slope(int i, int j) {
    return 1.0 * (f[i] - f[j]) / (s[i] - s[j]);
}

void input() {
    cin >> n >> M;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        s[i] = s[i - 1] + c[i];
    }
    return ;
}

void set_dp(int i, int j) {
    dp[i] = dp[j] + S(s[i] - s[j]) + M;
    f[i] = dp[i] + S(s[i]);//为了算斜率而准备
    return ;
}

long long solve() {
    head = tail = 0;
    q[tail++] = 0;//将0位置入队，必须要０入队因为，如果从０点转移就代表了只打印一次的情况！
    for (int i = 1; i <= n; i++) {
        while (tail - head >= 2 && slope(q[head + 1], q[head]) < 2 * s[i]) ++head;//出队操作
        set_dp(i, q[head]);
        while (tail - head >= 2 && slope(i, q[tail - 1]) < slope(q[tail - 2], q[tail - 1])) --tail;
        q[tail++] = i;
    }


    return dp[n];
}


int main() {
    input();
    cout << solve() << endl;
    return 0;
}
