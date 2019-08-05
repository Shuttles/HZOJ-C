/*************************************************************************
	> File Name: 191.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月05日 星期一 20时20分35秒
 ************************************************************************/

#include<iostream>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#define max_n 8000000
using namespace std;

int prime[max_n] = {0};

int main() {
    int l, r;
    cin >> l >> r;
    for (int m = 2; m <= max_n; m++) {
        if (!prime[m]) prime[++prime[0]] = m;
        for (int j = 1; j <= prime[0]; j++) {
            if (m * prime[j] > max_n) break;
            prime[m * prime[j]] = 1;
            if (m % prime[j] == 0) break;
        }
    }    
    int a = 0, b = max_n, c = 0, d = 0, cnt = 0;
    for (int i = prime[prime[0]]; i > 0; i--) {
        if (prime[i] >= l && prime[i] <= r && prime[i - 1] >= l && prime[i - 1] <= r) {
            cnt++;
            if ((prime[i] - prime[i - 1]) <= abs(b - a)) {
                b = prime[i];
                a = prime[i - 1];
            }
            if ((prime[i] - prime[i - 1]) >= abs(d - c)) {
                d = prime[i];
                c = prime[i - 1];
            }
        }  
    }
    if (!cnt) printf("There are no adjacent primes.\n");
    else printf("%d,%d are closest, %d,%d are most distant.\n", a, b, c , d);
    return 0;
}
