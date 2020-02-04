/*************************************************************************
	> File Name: 2.313.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月19日 星期一 18时19分33秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cinttypes>
using namespace std;

int main() {
    int64_t n, k;
    scanf("%" PRId64 "%" PRId64, &n, &k);
    int64_t sum = n * k;
    for (int64_t head = 1, tail, t; head <= n; head = tail + 1) {
        tail = (t = k / head) ? min(k / t, n) : n;
        sum -= t * (head + tail) * (tail - head + 1) >> 1;
    }
    printf("%" PRId64 "\n", sum);
    return 0;
}
