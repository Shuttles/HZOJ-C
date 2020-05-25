/*************************************************************************
	> File Name: 4.方程求解.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  5/24 19:47:28 2020
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

#define EPSILON 1e-5

double f(double x) {
    return x * exp(x);
}

double bs(double (*f)(double), double x) {
    double head = 0, tail = x;
    while (tail - head > EPSILON) {
        double mid = (head + tail) / 2;
        if (f(mid) < x) head = mid;
        else tail = mid;
    }
    return head;
}

int main() {
    double a;
    cin >> a;
    double ans = bs(f, a);
    printf("%.4lf\n", ans);

    return 0;
}
