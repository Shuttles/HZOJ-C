/*************************************************************************
	> File Name: 264.czy.1.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月10日 星期三 22时44分05秒
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

#define MAX_N 100000
long long h[MAX_N + 5], s[MAX_N + 5];
long long l[MAX_N + 5], r[MAX_N + 5];//记录左边/右边最近小于i的木板下标
int n, top = -1;

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    return ;
}

long long solve() {
    h[0] = h[n + 1] = -1;//挖坑
    top = -1;
    s[++top] = 0;
    for (int i = 1; i <= n; i++) {
        while (top != -1 && h[s[top]] >= h[i]) --top;
        l[i] = s[top];
        s[++top] = i;
    }

    top = -1;
    s[++top] = n + 1;
    for (int i = n; i >= 1; i--) {
        while (top != -1 && h[s[top]] >= h[i]) --top;
        r[i] = s[top];
        s[++top] = i;
    }

    long long  ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, h[i] * (r[i] - l[i] - 1));
    }
    return ans;
}

int main() {
    input();
    cout << solve() << endl;
    return 0;
}
