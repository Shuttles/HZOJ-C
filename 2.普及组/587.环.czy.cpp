/*************************************************************************
	> File Name: 587.环.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  5/ 6 18:07:05 2020
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    if ((a < b && b < c) || (a < b && c < a) || (a > b && a > c && b < c) ) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}
