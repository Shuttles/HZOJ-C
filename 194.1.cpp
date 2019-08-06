/*************************************************************************
	> File Name: 194.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月06日 星期二 20时08分53秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#define max_n 100000
using namespace std;

int binary_search(int num[], int n, int x);

int a[max_n + 5];

int main() {
    int n, s;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> s;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt) {
            printf("Yes\n");
            break;
        }
        if (binary_search(a, n, s - a[i])) cnt = 1;
    }
    !cnt && printf("No\n");
    return 0;
}

int binary_search(int num[], int n, int x) {
    int head, tail, mid;
    head = 1, tail = n;
    while (head <= tail) {
        mid = (head + tail) / 2;
        if (num[mid] == x) return mid;
        if (num[mid] < x) head = mid + 1;
        else tail = mid - 1 ;
    }
    return 0;
}
