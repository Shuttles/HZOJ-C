/*************************************************************************
	> File Name: 270.czy.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月12日 星期五 22时14分31秒
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

#define MAX_N 300000
int arr[MAX_N + 5], s[MAX_N + 5];//s是arr[]的前缀和数组
int q[MAX_N + 5];//s的单调队列，要使s[i] - s[j]最大，则s[j]就是滑动窗口内的最小值，所以q是单调递增队列
int head = 0, tail = 0;

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + arr[i];
        while (head - tail && s[q[tail - 1]] > s[i]) --tail;
        q[tail++] = i;
        if (q[head] < i - m) ++head;//注意这一定是<，因为这是前缀和数组的单调队列！
        //if (i < m) continue;//滑动窗口开始
        
        ans = max(ans, s[i] - s[q[head]]);
    }
    cout << ans << endl;
    return 0;
}
