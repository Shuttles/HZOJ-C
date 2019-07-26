/*************************************************************************
	> File Name: 128.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 19时47分09秒
 ************************************************************************/

#include<stdio.h>

int main() {
    double n;
    scanf("%lf", &n);
    int i, x, sum = 0;
    double ave;
    i = (int) (n);
    while (i) {
        scanf("%d", &x);
        sum += x;
        i--;
    }
    ave = sum / n;
    printf("%.2lf\n", ave);
    return 0;
}
