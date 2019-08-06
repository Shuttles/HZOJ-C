/*************************************************************************
	> File Name: 190.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月06日 星期二 14时43分01秒
 ************************************************************************/
//此题打完表之后不是循环素数表而是循环2～n/2！！！！！！
#include <stdio.h>
#define max_n 8000000

int prime[max_n + 5] = {0};
int i, j, n, cnt = 0;

int main() {
    scanf("%d", &n);
    for (i = 2; i * i <= max_n; i++) {
        if (!prime[i]) {
            for (j = i * i; j <= max_n; j += i) {
                prime[j] = 1;
            }
        }
    }
    if (!prime[n - 2]) cnt++;
    for (i = 3; i <= n /2; i += 2) {
        if (!prime[i] && !prime[n - i]) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
