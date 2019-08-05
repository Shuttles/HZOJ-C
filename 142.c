/*************************************************************************
	> File Name: 142.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月27日 星期六 11时26分31秒
 ************************************************************************/
#include<stdio.h>

int is_val(int x);
int is_prime(int x);

int main() {
    int i, j, m, flag = 0;
    int a, b;
    scanf("%d%d", &a, &b);
    for (i = a; i <= b; i++) {
        if (is_val(i) && is_prime(i)) {
            flag == 1 && printf(" ");
            printf("%d", i);
            flag = 1;
        }
    }
    return 0;
}

int is_val(int x) {
    int temp = x, sum = 0;
    while (x) {
        sum = sum * 10 + x % 10;
        x /= 10;
    }
    return temp == sum;
}
int is_prime(int x) {
    int i;
    for (i = 2; i * i <= x; i++) {
        if (!(x % i)) return 0;
    }
    return 1;
}
