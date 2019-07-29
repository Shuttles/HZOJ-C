/*************************************************************************
	> File Name: 143.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月27日 星期六 11时06分36秒
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

int pingfang(int x) {
    int i;
    for (i = 1; i <= 9; i++) {
        if (i * i == x)  return 1;
    }
    return 0;
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int i;
    int AB, CD;
    int count = 0;
    int flag = 0;
    for (i = a; i <= b; i++) {
        AB = 10 * (i / 1000) + i % 1000 / 100;
        CD = i % 100;
        if (!(i % 6) && panduan(AB) && pingfang(CD)) {
            if (flag) printf(" ");
            printf("%d", i);
            flag = 1;
            count++;
        }
    }
    printf("\n%d\n", count);
    return 0;
}
