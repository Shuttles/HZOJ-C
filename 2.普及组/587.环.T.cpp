/*************************************************************************
	> File Name: 587.环.T.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  5/ 6 18:21:04 2020
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int a, b, c, d = 0;
    cin >> a >> a >> b >> c;
    if (a > b) d++;
    if (b > c) d++;
    if (c > a) d++;
    if (d == 2) cout << 0 << endl;
    else cout << 1 << endl;

    return 0;
}
