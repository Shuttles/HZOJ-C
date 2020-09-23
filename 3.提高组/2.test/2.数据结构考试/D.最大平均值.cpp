/*************************************************************************
	> File Name: D.最大平均值.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  5/30 14:51:24 2020
 ************************************************************************/
#include<iostream>
#include <cinttypes>
#include <cstdio>
#include <algorithm>
using namespace std;




#define INF 0x3f3f3f3f
#define MAX_N 100000
int64_t a[MAX_N + 5],  b[MAX_N + 5];
int64_t sum[MAX_N + 5];
int n, m;

bool check(int A) {
    for (int i = 1; i <= n; i++) {
        b[i] = a[i] - A;
        sum[i] = b[i] + sum[i - 1];
    }


    int64_t Y = 0;
    for (int j = m; j <= n; j++) {
        Y = min(Y, sum[j - m]);
        if (sum[j] - Y >= 0) return true;
    }
    return false;
}

int bs(int l, int r) {
    if (l == r) return l;
    int mid = (l + r + 1) >> 1;
    if (check(mid)) return bs(mid, r);
    return bs(l, mid - 1);

}


int main() {
    cin >> n >> m;
    int64_t l = INF, r = -INF;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] *= 1000;
        l = min(l, a[i]);
        r = max(r, a[i]);
    }
    cout << bs(l ,r) << endl;

    return 0;
}
