/*************************************************************************
	> File Name: 391.数列分段.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2020年09月22日 星期二 20时19分37秒
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

long long n, m, num[MAX_N + 5], tl, tr;

long long func2(long long sum) {
    long long now = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (now + num[i] == sum) {
            cnt += 1;
            now = 0;
        } else if (now + num[i] > sum) {
            cnt++;
            now = num[i];
        } else {
            now += num[i];
        }
    }
    if (now) {
        cnt++;
    }
    return cnt;
}

long long func() {
    while (tl - tr) {
        long long  mid  = (tl + tr) / 2;
        long long s = func2(mid);
        if (s > m) {
            tl = mid + 1;
        } else {
            tr = mid;
        }
    }
    return tl;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        tl = max(tl,num[i]);
        tr += num[i];
    }
    cout << func() << endl;
    return 0;
}
