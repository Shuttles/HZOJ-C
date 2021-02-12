/*************************************************************************
	> File Name: 372.czy.1.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月12日 星期五 21时36分58秒
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

#define MAX_N 500000
int a[MAX_N + 5], b[MAX_N + 5];
int qa[MAX_N + 5], qb[MAX_N + 5];//a、b对应的单调队列
int head_a = 0, tail_a = 0;
int head_b = 0, tail_b = 0;

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    
    for (int i = 1; i <= n; i++) {
        ans = i;
        while (head_a - tail_a && a[qa[tail_a - 1]] > a[i]) --tail_a;
        qa[tail_a++] = i;
        while (head_b - tail_b && b[qb[tail_b - 1]] > b[i]) --tail_b;
        qb[tail_b++] = i;
        if (tail_a - tail_b) break;
    }
    cout << ans - 1 << endl;
    return 0;
}
