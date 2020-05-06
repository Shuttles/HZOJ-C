/*************************************************************************
	> File Name: 589.胡船长请看电影.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  5/ 6 18:43:35 2020
 ************************************************************************/

//纸老虎！！！！！！
#include<iostream>
using namespace std;

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    int n, k, id, a, b;
    cin >> n >> k >> id;
    if (n == k) {
        cout << "1/1" << endl;
    } else {
        int x = gcd(n, k);
        a = k / x;
        b = n / x;
        cout << a << "/" << b << endl;
    }


    return 0;
}
