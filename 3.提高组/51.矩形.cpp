/*************************************************************************
	> File Name: 51.矩形.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月13日 星期六 20时16分29秒
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

#define MAX_N 1000
#define MOD_NUM 100007
int conti[MAX_N + 5][MAX_N + 5];//conti[i][j]代表(i, j)头顶上有几个连续矩形
int s[MAX_N + 5], top;//单调递增栈
int f[MAX_N + 5];
int n, m;


void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> conti[i][j];
            if (conti[i][j]) conti[i][j] += conti[i - 1][j];
        }
    }
    return ;
}

long long solve() {
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        top = -1;
        s[++top] = 0;
        conti[i][0] = -1;//挖坑
        f[0] = 0;
        for (int j = 1; j <= m; j++) {
            while (top != -1 && conti[i][s[top]] >= conti[i][j]) --top;
            f[j] = conti[i][j] * (j - s[top]) + f[s[top]];//右侧＋左侧
            s[++top] = j;

            f[j] %= MOD_NUM;
            ans += f[j];
            ans %= MOD_NUM;
        }
    }
    return ans;
}


int main() {
    input();
    cout << solve() << endl;
    return 0;
}
