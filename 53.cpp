/*************************************************************************
	> File Name: 53.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月23日 星期五 15时39分23秒
 ************************************************************************/

#include <iostream>
#include <cinttypes>
#define max_n 1000000
using namespace std;

int prime[max_n + 5];
int64_t cnt[max_n + 5];
int64_t sum[max_n + 5];
void init();

int main() {
    init();
    int64_t ans = 0;
    for (int i = 1; i <= max_n; i++) {
        if (sum[i] > ans) ans = sum[i];
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            cnt[i] = i * i;
            sum[i] = 1 + i;
        }
        for (int j = 1; j <= prime[0] && (i * prime[j] <= max_n); j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j]) {
                sum[i * prime[j]] = sum[i] * sum[prime[j]];
                cnt[i * prime[j]] = prime[j] * prime[j];
            } else {
                sum[i * prime[j]] = sum[i] *(1 - cnt[i] * prime[j]) / (1 - cnt[i]);
                cnt[i * prime[j]] = prime[j] * cnt[i];
                break;
            }
        }
    }
    return;
}
