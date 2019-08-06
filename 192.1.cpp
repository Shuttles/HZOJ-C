/*************************************************************************
	> File Name: 192.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月06日 星期二 15时45分24秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cinttypes>
#include <cmath>
#define EPSILON 1e-6
long double head, tail, mid, a;

long double f(long double x) {
    return x * exp(x) - a;
}

long double f_prime(long double x) {
    return (1 + x) * exp(x);
}

long double newton(long double (*fp)(long double), long double (*fp_prime)(long double)) {
    long double x = a ;
    while (fabs(fp(x)) > EPSILON) {
        x = x - fp(x) / fp_prime(x);
    }
    return x;
}

int main() {
    scanf("%Lf", &a);
    printf("%.4Lf\n", newton(f, f_prime));
    return 0;
}


