/*************************************************************************
	> File Name: 192.3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月06日 星期二 17时37分30秒
 ************************************************************************/

#include <cstdio>
#include <cmath>
#define EPSILON 1e-6

double f(double x) {
    return x * exp(x);
}

int main() {
    double a;
    scanf("%lf", &a);
    double l, r, mid;
    l = 0, r = 31;
    while (r - l > EPSILON) {
        mid = (l + r) / 2;
        if (f(mid) > a) r = mid;
        else l = mid;
    }
    printf("%.4lf\n", l);
    return 0;
}
