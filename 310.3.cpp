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
    long long n;
    scanf("%d", &n);
    init(n);
    //int temp = i;
    for (int j = 1; j <= prime[0]; j++) {
        long long tmp = prime[j], cnt = 0;
        while (tmp <= n) {
            cnt += n / tmp;
            tmp *= prime[j];
        }
        cout << prime[j] << " " << cnt << endl;
    }
    return 0;
}
