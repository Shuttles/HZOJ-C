/*************************************************************************
	> File Name: 271.czy.3.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月09日 星期二 11时52分48秒
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
int q[MAX_N + 5], head = 0, tail = 0;
int val[MAX_N + 5];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    //最小值　维护单调递增队列
    for (int i = 1; i <= n; i++) {
        while (tail - head && val[q[tail - 1]] > val[i]) --tail;
        q[tail++] = i;
        if (q[head] <= i - k) head++;//出队列

        if (i >= k) {
            i > k && cout << " ";
            cout << val[q[head]];
        }
    }
    cout << endl;

    //最大值　维护单调递减队列
    head = tail = 0;
    for (int i = 1; i <= n; i++) {
        while (tail - head && val[q[tail - 1]] < val[i]) --tail;
        q[tail++] = i;
        if (q[head] <= i - k) head++;//出队列

        if (i >= k) {
            i > k && cout << " ";
            cout << val[q[head]];
        }
    }
    cout << endl;
    return 0;
}
