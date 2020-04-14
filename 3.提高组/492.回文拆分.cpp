/*************************************************************************
	> File Name: 492.回文拆分.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  4/14 16:36:16 2020
 ************************************************************************/

#include<iostream>
using namespace std;

int dp[30] = {0, 0, 1, 1, 3};

int main() {
    int k;
    cin >> k;
    for (int i = 5; i <= k; i++) {
        if ((i & 1) == 0) {
            dp[i] = dp[i - 1] * 2 + 1;
        } else {
            dp[i] = dp[i - 1];
        }
    }
    cout << dp[k] << endl;
    return 0;
}
