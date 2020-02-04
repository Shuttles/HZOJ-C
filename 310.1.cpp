/*************************************************************************
	> File Name: 310.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月28日 星期六 14时11分54秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 1000000

int prime[MAX_N + 6], f[MAX_N + 5], cnt[MAX_N + 5];

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            f[i] = 2;
            cnt[i] = 1;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j]) {
                f[i * prime[j]] = f[i] * f[prime[j]];
                cnt[i * prime[j]] = 1;
            } else {
                f[i * prime[j]] = f[i] / (cnt[i] + 1) * (cnt[i] + 2);
                cnt[i * prime[j]]  = cnt[i] + 1;
                break;
            }
        }
    }
    return ;
}


int main() {
    init();
    int n;
    scanf("%d", &n);
    for (int i = 1; prime[i] <= n; i++) {
        printf("%d ", prime[i]);
        int cnt = 0;
        int temp = 1;
        for (int j = 2; j <= n; j++) {
            temp *= j;
            while (temp % prime[i] == 0) temp /= prime[i], cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
