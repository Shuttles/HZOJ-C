/*************************************************************************
	> File Name: 117.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月28日 星期日 22时14分52秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int a, b, c = 0;//用ａ读入数，ｂ来存ａ的原来的值，ｃ存储倒序后的值
    cin >> a;
    b = a;
    while (a) {
        c = c * 10 + a % 10;
        a /= 10;
    }
    cout << (b - c ? "NO" : "YES") << endl;
    return 0;
}
