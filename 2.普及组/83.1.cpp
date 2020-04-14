/*************************************************************************
	> File Name: 83.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  3/11 20:07:32 2020
 ************************************************************************/

#include<iostream>
using namespace std;

int n, m, ans = 0;

int func(int s, int left_num, int left_cnt) {
    if (left_cnt == 0) {
        if (left_num == 0) return 1;
        return 0;
    }
    int ans = 0;
    for (int i = s; i <= left_num; i++) {
        ans += func(i, left_num - i, left_cnt - 1);
    }
    return ans;
}

int main() {
    cin >> n >> m;
    cout << func(1, n, m) << endl;
    return 0;
}
