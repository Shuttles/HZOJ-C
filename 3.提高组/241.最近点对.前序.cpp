/*************************************************************************
	> File Name: 241.最近点对.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  5/ 6 19:00:03 2020
 ************************************************************************/

//即给出一组点，求两两之间的最短距离！
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX_N 100000
#define INF 0x3f3f3f3f

struct Node {
    double x, y;
};

int n;
Node p[MAX_N + 5];

bool cmp(Node a, Node b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

double dis(int p1, int p2) {
    return sqrt((p[p1].x - p[p2].x) * (p[p1].x - p[p2].x) + (p[p1].y - p[p2].y) * (p[p1].y - p[p2].y));
}


double func(int l, int r) {
    if (l == r) {
        return 2100000000;
    }
    if (l + 1 == r) {
        return dis(l, r);
    }
    int mid = (l + r) >> 1;
    double d = min(func(l, mid), func(mid + 1, r));
    for (int i = mid; i >= 0 && (p[mid].x - p[i].x < d); i--) {
        for (int j = mid + 1; j < r && (p[j].x - p[mid].x < d); j++) {
            d = min(d, dis(i, j));
        }
    }
    return d;
}


int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf", &p[i].x, &p[i].y);
    }
    sort(p, p + n, cmp);
    double ans = func(0, n - 1);
    printf("%lf\n", ans);
    return 0;
}
