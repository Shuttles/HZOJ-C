/*************************************************************************
	> File Name: 185.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月30日 星期二 14时19分33秒
 ************************************************************************/

#include<iostream>
using namespace std;

int f(int n);

int main() {
    int n;
    cin >> n;
    cout << f(n) <<endl;
    return 0;
}

int f(int n){
    if (n == 1 || n == 2) return 1;
    return f(n - 1) +f(n - 2);
}
