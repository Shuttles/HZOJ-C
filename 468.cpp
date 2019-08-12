/*************************************************************************
	> File Name: 468.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月12日 星期一 20时27分50秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int a, int b) {
    return (b ? (gcd(b, a % b)) : a);
}
int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    printf("%d\n", gcd(m, n));
    return 0;
}
