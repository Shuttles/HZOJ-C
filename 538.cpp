/*************************************************************************
	> File Name: 538.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  3/25 18:15:51 2020
 ************************************************************************/

#include<iostream>
using namespace std;

int n, num[25][25], check[25], flag;

void func(int x) {
    if (flag == 1) {
        cout << "-";
    }
    flag = 1;
    cout << x;
    for (int i = 1; i <= n; i++) {
        if (num[x][i] == 1 && check[i] == 0) {
            check[i] = 1;
            func(1);
        }
    }
}


int  main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; i++) {
            cin >> num[i][j];
        }
    }
    return 0;
}
