/*************************************************************************
	> File Name: 179.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月06日 星期二 21时22分59秒
 ************************************************************************/
#include <cstdio>
#include <cmath>
#define EPSILON 1e-7

double bisection(int p, int q, double (*func)(int, int, double));

double f(int p, int q, double x);

int main() {
    int p;
    int q;
    scanf("%d %d", &p, &q);
    printf("%.4lf\n", bisection(p, q, f));
    return 0;
}

double bisection(int p, int q, double (*func)(int, int, double)) {
    double head = -20.0;
    double tail = 20.0;
    double mid;
    while (fabs(tail - head) > EPSILON) {
        mid = (head + tail) / 2;
        if (f(p, q, mid) == 0) return mid;
        if (f(p, q, mid) * f(p, q, head)< 0) tail = mid;
        else head = mid;
    }
    return tail;
}

double f(int p, int q, double x) {
    return p * x + q;
}
