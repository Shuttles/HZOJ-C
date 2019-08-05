/*************************************************************************
	> File Name: 188.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月05日 星期一 20时53分11秒
 ************************************************************************/

#include<iostream>
#define max_n 1000000
using namespace std;

int prime[max_n] = {};

int main() {
    for (int m = 2; m <= max_n; m++) {
        if (!prime[m]) prime[++prime[0]] = m;
        for (int j = 1; j <= prime[0]; j++) {
            if (m * prime[j] > max_n) break;
            prime[m * prime[j]] = 1;
            if (m % prime[j] == 0) break;
        }
    }
    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= prime[0]; i++) {
        if (prime[i] >= M && prime[i] <= N) printf("%d\n", prime[i]);
    }
    return 0;
}
