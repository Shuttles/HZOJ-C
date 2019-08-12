/*************************************************************************
	> File Name: 467.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月12日 星期一 20时23分00秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cinttypes>
using namespace std;

int64_t factorial(int64_t x);
int64_t keep[30];

int main() {
    int64_t n;
    scanf("%" PRId64, &n);
    printf("%" PRId64 "\n", factorial(n));
    return 0;
}

int64_t factorial(int64_t x) {
    if (x == 1 || x == 0) return 1;
    if (keep[x]) return keep[x];
    int64_t temp;
    temp = factorial(x - 1) * x;
    if (x < 30 && !keep[x])
        keep[x] = temp;
    return temp;
}

