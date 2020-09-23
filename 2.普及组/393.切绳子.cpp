/*************************************************************************
	> File Name: 393.切绳子.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2020年09月22日 星期二 19时55分06秒
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

int n, k;
double num[MAX_N + 5], tr;

int func2(double len) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += num[i] / len;
    }
    return s;
}

double func() {
    double l = 0, r = tr;
    while (r - l > 0.00001) {
        double mid = (l + r) / 2;
        int s = func2(mid);
        if (s >= k) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        tr = max(tr, num[i]);
    }
    double ans = func();
    printf("%.2f\n", (int)(ans * 100) / 100.0);
    return 0;
}
