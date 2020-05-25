/*************************************************************************
	> File Name: 5.统计闰年.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  5/24 19:28:57 2020
 ************************************************************************/

#include <iostream>
using namespace std;

bool is_leapyear(int x) {
    if ((x % 400 == 0) || (x % 4 == 0 && x % 100)) return true;
    return false;
}

int main() {
    int x, y;
    cin >> x >> y;
    int ans = 0;
    for (int i = x; i <= y; i++) {
        if (is_leapyear(i) == false) continue;
        ans += 1;
    }
    cout << ans << endl;
    return 0;
}
