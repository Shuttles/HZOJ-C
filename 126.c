/*************************************************************************
	> File Name: 126.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 13时58分09秒
 ************************************************************************/

#include<stdio.h>
#include <math.h>
#define PI 3.14
int main() {
    double r1, r2;
    scanf("%lf%lf", &r1, &r2);
    printf("%.2f\n", PI * (r1 * r1 - r2 * r2));
    return 0;
}
