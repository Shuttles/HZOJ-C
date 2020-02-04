/*************************************************************************
	> File Name: 310.2.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月28日 星期六 14时42分42秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 1000000

int prime[MAX_N + 5];

void init(int n) {
    for (int i = 2; i <= n ; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] <= n; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int cnt[MAX_N + 5];

int main() {
    int n;
    scanf("%d", &n);
    init(n);
    for (int i = 2; i <= n; i++) {
        int temp = i;
        for (int j = 1; j <= prime[0] && temp >= prime[j]; j++) {
            while (temp % prime[j] == 0) temp /= prime[j], cnt[prime[j]]++;
        }
    }
    for (int i = 1; i <= prime[0]; i++) {
        if (!cnt[prime[i]]) continue;
        cout << prime[i] << " " << cnt[prime[i]] << endl;
    }
    return 0;
}
