/*************************************************************************
	> File Name: 1.a^b.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  5/24 19:35:21 2020
 ************************************************************************/

#include <iostream>
#include <cinttypes>
using namespace std;

int main() {
    int64_t a, b, p, temp;
    cin >> a >> b >> p;
    temp = a;
    for (int i = 1; i <= b; i++) {
        a %= p;
        (i == b) || (a *= temp);
    }
    cout << a << endl;
    return 0;
}
