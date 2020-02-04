/*************************************************************************
	> File Name: 2.243.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月23日 星期五 11时07分38秒
 ************************************************************************/

#include <iostream>
#include <cinttypes>
#define max_n 20000000
using namespace std;

int64_t s[max_n + 5], e[max_n + 5], d[max_n + 5];
int64_t sum(int64_t n, int64_t x);

int main() {
    int64_t T;
    scanf("%" PRId64, &T);
    int64_t n;
    while (T--) {
        scanf("%" PRId64, &n);
        for (int64_t i = 1; i <= n; i++) scanf("%" PRId64 "%" PRId64 "%" PRId64, &s[i], &e[i], &d[i]);
        int64_t l = 1, r = INT32_MAX;
        if (!(sum(n, r) & 1)) {
            printf("Poor QIN Teng:(\n");
            continue;
        }
        while (l < r) {
            int64_t mid = (l + r) >> 1;
            if (!(sum(n, mid) & 1)) l = mid + 1;
            else r = mid;
        }
        if (sum(n, l) & 1) printf("%" PRId64 " " "%" PRId64 "\n", l, sum(n, l) - sum(n, l - 1));  //骚操作，用前ｎ项和－前ｎ－　１项和
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
