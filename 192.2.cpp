/*************************************************************************
	> File Name: 192.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月06日 星期二 16时31分41秒
 ************************************************************************/

#include <stdio.h>
#include <cmath>
#include <cinttypes>
#define EPSILON 1e-6

double f(double x);

double bisection(double (*f)(double), double a);


int main() {
    double a;
    scanf("%lf", &a);
    printf("%.4lf\n", bisection(f, a));
    return 0;
}

double f(double x) {
    return x * exp(x);
}

double bisection(double (*f)(double), double a) {
    double head, tail, mid;
    head = 0.0, tail = 31.0;
    while (1) {
        mid = (head + tail) / 2;
        if (fabs(f(mid) - a) < EPSILON) return mid;
        if (f(mid) < a) head = mid;
        else tail = mid;
    }
}
