/*************************************************************************
	> File Name: 142.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月27日 星期六 11时26分31秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int panduan(int x) {
    int i;
    for (i = 2; i <= sqrt(x); i++) {
        if (!(x % i)) return 0;
    }
    return 1;
}

int huiwen(int x) {
    int a;
    a = x / 10000 + 10 * (x % 10000 / 1000) + 100 * (x % 1000 / 100) + 1000 * (x % 100 / 10) + 10000 * (x % 10);
    return a;
}
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int flag = 0;
    int i;
    for (i = a; i <= b; i++) {
        if (panduan(i) && !(huiwen(i) - i)) {
            if (flag) printf(" ");
            printf("%d", i);
            flag = 1;
        }
    }
    return 0;
}
