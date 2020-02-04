/*************************************************************************
	> File Name: 2.79.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月23日 星期五 14时23分35秒
 ************************************************************************/

#include <iostream>
#define max_n 10000000
using namespace std;

int prime[max_n + 5];
int is_prime[max_n + 5] = {1, 1};
void init();

int main() {
    init();
    int a, b;
    scanf("%d%d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (!is_prime[i]) 
            printf("%d\n", i);
    }
    return 0;
}

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && (i * prime[j] <= max_n); j++) {
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return;
}
