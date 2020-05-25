/*************************************************************************
	> File Name: 3.交换两位数.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  5/24 19:25:23 2020
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int x = n / 10;
    int y = n % 10;
    int ans = y * 10 + x;
    cout << ans << endl;
    return 0;
}
