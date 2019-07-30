/*************************************************************************
	> File Name: 184.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月30日 星期二 10时26分45秒
 ************************************************************************/

#include<iostream>
using namespace std;

int number(int n);

int main() {
    int n;
    cin >> n;
    cout << number(n) << endl;
    return 0 ;
}

int number(int n) {
    if (n == 1) return 1;
    return (number(--n) + 1) * 2;
}
