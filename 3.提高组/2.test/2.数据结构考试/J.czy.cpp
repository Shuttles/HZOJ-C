/*************************************************************************
	> File Name: 2.243.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月23日 星期五 11时07分38秒
 ************************************************************************/

#include <iostream>
#include <cinttypes>
#define MAX_N 200000
using namespace std;

int64_t s[MAX_N + 5], e[MAX_N + 5], d[MAX_N + 5];
int64_t sum(int64_t n, int64_t x);
int64_t check(int64_t n, int64_t x);
int64_t bs(int64_t l, int64_t r, int64_t n);


int main() {
    int64_t T;
    scanf("%" PRId64, &T);
    while (T--) {
        int64_t n, l = INT32_MAX, r = INT32_MIN;
        scanf("%" PRId64, &n);
        for (int64_t i = 1; i <= n; i++) {
            scanf("%" PRId64 "%" PRId64 "%" PRId64, &s[i], &e[i], &d[i]);
            l = min(l, s[i]);
            r = max(r, e[i]);
        }
        int64_t pos = bs(l, r, n);
        int64_t ans = sum(n, pos) - sum(n, pos - 1);
        if (ans % 2) {
            printf("%" PRId64 " %" PRId64 "\n", pos, ans);
        } else {
            printf("Poor QIN Teng:(\n");
        }
    }
    return 0;
}

int64_t sum(int64_t n, int64_t x) {
    int64_t ans = 0;
    for (int64_t i = 1; i <= n; i++) {
        if (s[i] > x) continue;
        ans += (min(e[i], x) - s[i]) / d[i] + 1;                     //数学规律的总结
    }
    return ans;
}


int64_t check(int64_t n, int64_t x) {
    return sum(n, x) % 2;//返回1表示成功，存在奇数
}


int64_t bs(int64_t l, int64_t r, int64_t n) {
    if (l == r) return l;
    int64_t mid = (l + r) >> 1;
    if (check(n, mid)) return bs(l, mid, n);
    return bs(mid + 1, r, n);
}
