/*************************************************************************
	> File Name: 187.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月30日 星期二 16时41分33秒
 ************************************************************************/

#include <iostream>
#include <cinttypes>
using namespace std;

int64_t m(int n);
int64_t b(int n);

int main() {
    int n;
    cin >> n;
    cout << m(n) << " " << b(n) << endl;
    return 0;
}

int64_t m(int n) {
    if (n == 1) return 1;
    return m(n - 1) * 2 + 1;
}

int64_t b(int n) {
    if (n == 1) return 1;
    return b(n - 1) * 2 + n;
}
