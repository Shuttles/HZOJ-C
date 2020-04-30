/*************************************************************************
	> File Name: 559.小毛的交易.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  4/29 18:43:11 2020
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <cstdio>

#define MAX_N 1000
using namespace std;

struct node {
    double a, b, c;
};

bool cmp(node a, node b) {
    return a.c > b.c;
}


node arr[MAX_N + 5];


int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].a >> arr[i].b;
        arr[i].c = (arr[i].a / arr[i].b);
    }
    sort(arr, arr + 50, cmp);
    

    double ans = 0;
    int i = 0;
    while (m > 0 && i < n) {
        if (m >= arr[i].b) {
            m -= arr[i].b;
            ans += arr[i].a;
        } else {
            ans += m * arr[i].c;
            m = 0;
        }
        i++;
    }
    printf("%.3f\n", ans);
    return 0;
}
