/*************************************************************************
	> File Name: 591.游戏.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  5/ 6 20:32:27 2020
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (n & 1) {
        //奇数
        int mid = (n + 1) >> 1;//为什么要上取整？细品！联系下一行的 < !!!
        if (m < mid) cout << m + 1 << endl;
        else cout << m - 1 << endl;
    } else {
        //偶数
        int mid = n >> 1;
        if (m <= mid) cout << m + 1 << endl;
        else cout << m - 1 << endl;
    }

    return 0;
}
