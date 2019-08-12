/*************************************************************************
	> File Name: 465.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月12日 星期一 20时40分45秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cinttypes>
using namespace std;

int digit(int64_t n, int k);

int main() {
    int64_t n;
    int k;
    scanf("%" PRId64, &n);
    scanf("%d", &k);
    printf("%d\n", digit(n, k));
    return 0;
}

int digit(int64_t n, int k) {
    int ans;
    while (k--) {
        ans = n % 10;
        n /= 10;
    }
    return ans;
}
