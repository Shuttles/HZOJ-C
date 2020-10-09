/*************************************************************************
	> File Name: 389.暴躁的程序猿.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2020年09月22日 星期二 19时41分33秒
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
int n, m, num[MAX_N + 5];

int func2(int dis) {
    int s = 1, last = num[0];
    for (int i = 1; i < n; i++) {
        if (num[i] - last >= dis) {
            s++;
            last = num[i];
        }
    }
    return s;
}


int func() {
    int l = 1, r = num[n - 1] - num[0];
    while (l - r) {
        int mid = (l + r + 1) / 2;
        int s = func2(mid);
        if (s >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    cout << func() << endl;
    return 0;
}
