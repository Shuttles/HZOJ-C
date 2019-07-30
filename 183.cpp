/*************************************************************************
	> File Name: 183.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月30日 星期二 10时12分36秒
 ************************************************************************/

#include<iostream>
using namespace std;

int f(int x);

int main() {
    int x;
    cin >> x;
    cout << f(x) << endl;
    return 0;
}

int f(int x) {
    if (x <= 0) return 0;
    if (x == 1) return 1;
    if (x > 1 && !(x & 1)) return 3 * f(x / 2) - 1;
    if (x > 1 && x & 1) return 3 * f((x + 1) / 2) - 1;
}
