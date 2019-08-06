/*************************************************************************
	> File Name: 189.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月06日 星期二 12时01分12秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#define max_n 1000000
using namespace std;

int num[max_n + 5] = {0};

int binary_search(int a[max_n + 5], int n, int x);

int N, K;
int main() {
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &num[i]);
    }

    int t = 0;
    for (int j = 1; j <= K; j++) {
        scanf("%d", &t);
        j == 1 || printf(" ");
        printf("%d", binary_search(num, N, t));
    }
    return 0;
}

int binary_search(int a[max_n + 5], int n, int x) {
    int head = 1, tail = n, mid;
    while (head <= tail) {
        mid = (head + tail) / 2;
        if (a[mid] == x) return mid;
        if (a[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}
