/*************************************************************************
	> File Name: 195.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月06日 星期二 20时54分51秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#define max_n 100000
using namespace std;

int a[max_n + 5];

int binary_search(int num[], int n, int x);

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int flag = 0;
    while (m--) {
        int q;
        cin >> q;
        if (q < a[1]) {
            flag && printf(" ");
            printf("%d", a[1]);
            flag = 1;
        } else {
            flag && printf(" ");
            printf("%d", a[binary_search(a, n, q)]);
            flag = 1;
        }
    }
    return 0;
}

int binary_search(int num[], int n, int x) {
    int head, tail, mid;
    head = 1, tail = n;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == x) return mid;
        if (num[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    return tail;
}

