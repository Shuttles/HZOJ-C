/*************************************************************************
	> File Name: 2.小k的存款.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  5/22 19:14:00 2020
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        double n, x;
        int m;
        cin >> n >> x >> m;
        x += 1;
        double ans = n;
        for (int i = 1; i <= m; i++) {
            ans = (long long)ans * x + n;
        }
        cout << (long long)ans << endl;
    }

    return 0;
}
