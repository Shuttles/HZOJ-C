/*************************************************************************
	> File Name: 386.czy.cpp
	> Author: 
	> Mail: 
	> Created Time: 日 10/18 16:54:30 2020
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_M 100000
struct node {
    long long num, cnt;
};

node x[MAX_M + 5];

long long y[MAX_M + 5];


long long bs(int m, long long target) {
    long long head = 1, tail = m;
    while (head <= tail) {
        long long mid = (head + tail) >> 1;
        if (x[mid].cnt == target) return x[mid].num;
        if (x[mid].cnt < target) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

bool cmp(node a, node b) {
    return a.cnt < b.cnt;
}

int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        int cnt;
        cin >> cnt;
        x[i].num = i, x[i].cnt = cnt;
    }
    for (int i = 1; i <= n; i++) cin >> y[i];

    sort(x + 1, x + 1 + m, cmp);
    for (int i = 1; i <= n; i++) {
        cout << bs(m, y[i]) << endl;
    }
    return 0;
}
