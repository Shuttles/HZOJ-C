/*************************************************************************
	> File Name: 59.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月23日 星期五 16时53分45秒
 ************************************************************************/

#include <iostream>
#include <cstdarg>
using namespace std;
int sum(int n, ...);

int main() {
    

    return 0;
}

int sum(int n, ...) {
   double sum = 0.0;
    va_list arg;
    va_start(arg, n);
    int i = 0;
    for (i = 0; i < n; i++) {
        sum += va_arg(arg, double);
    }
    va_end(arg);
}mZ
