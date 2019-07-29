/*************************************************************************
	> File Name: 110.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月28日 星期日 21时21分15秒
 ************************************************************************/
//整个过程不采用if判断
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    double x;
    cin >> x;
    double y;
    y = (x > 15 ? 15 : x) * 6 + (x > 15) * (x - 15) * 9;
    printf("%.2lf\n", y);
    return 0;
}
