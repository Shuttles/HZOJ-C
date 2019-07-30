/*************************************************************************
	> File Name: 186.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月30日 星期二 14时31分55秒
 ************************************************************************/

#include <iostream>
using namespace std;

int number(int x, int p);

int a[100001] = {0};

int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int x = 1;
    int p = 1;
    cout << number(x, p) << endl;
    return 0;
}

int number(int x, int p) {
    if (p > n) return x - 1;
    return number(++x, p + a[p]);
} 
