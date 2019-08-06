/*************************************************************************
	> File Name: 193.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月06日 星期二 19时43分06秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cinttypes>
#define max_n 100000
using namespace std;
int a[max_n + 5];

int binary_search(int num[],int n,int x);

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);        
    }
    int k, s;
    int x;
    scanf("%d%d", &k, &s);
    x = s - k;
    if (binary_search(a, n, x)) printf("Yes\n");
    else printf("No\n");
    return 0;
}

int binary_search(int num[], int n, int x) {
    int head, tail, mid;
    head = 0, tail = n - 1;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == x) return mid;
        if (num[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}
