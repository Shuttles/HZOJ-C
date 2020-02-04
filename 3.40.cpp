/*************************************************************************
	> File Name: 3.40.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月14日 星期三 20时04分24秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cinttypes>
#define max_n 500
using namespace std;

int ans[max_n + 5][100] = {{1, 0}, {1, 0}, {1, 1}, {1, 1}};

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 4; i <= max_n; i++) {
        int *a = ans[i], *b = ans[i - 2], *c = ans[i - 3];
        for (int j = 1; j <= b[0]; j++) {
            a[j] = b[j] + c[j];
        }
        a[0] = b[0];
        for (int j = 1; j <= a[0]; j++) {
            if (a[j] < 10) continue;
            a[j + 1] += a[j] / 10;
            a[j] %= 10;
            a[0] += (j == a[0]);
        }
    }
    for (int i = ans[n][0]; i > 0; i--) {
        printf("%d", ans[n][i]);
    }
    printf("\n");
    return 0;
}
