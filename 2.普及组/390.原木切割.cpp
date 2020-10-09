/*************************************************************************
	> File Name: 390.原木切割.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2020年09月22日 星期二 19时24分09秒
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

int n, m, num[MAX_N + 5], tr;

int func2(int len) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += num[i] / len;
    }
    return s;
}

int func() {
    int l = 1, r = tr;
    while (l - r) {
        int mid = (l + r + 1) >> 1;
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
        tr = max(tr, num[i]);
    }

    cout << func() << endl;

    return 0;
}
