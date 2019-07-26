/*************************************************************************
	> File Name: 130.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 20时03分52秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    double m;
    double sum = 0;
    scanf("%lf%d", &m, &n);
    while (n--) {
        sum = (m + sum) * 1.00417;
    }
    printf("$%.2lf\n", sum);
    return 0;
}
