/*************************************************************************
	> File Name: 109.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月28日 星期日 21时16分04秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int a, flag = 1;//原本是奇数状态
    cin >> a;
    while (a && flag) {
        flag = (a & 1);
        a /= 10;
    }
    cout << (flag ? "NO" : "YES");


    return 0;
}
