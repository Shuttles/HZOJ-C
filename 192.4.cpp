/*************************************************************************
	> File Name: 192.4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月06日 星期二 17时45分43秒
 ************************************************************************/

#include <cstdio>
#include <cmath>
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
    double l, r, mid;
    l = 0, r = 31;
    while (r - l > EPSILON) {
        mid = (l + r) / 2;
        if (f(mid) == a) return mid;
        if (f(mid) < a) l = mid;
        else r = mid;
    }
    return l;
}
