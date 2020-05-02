/*************************************************************************
	> File Name: 45.最长公共子序列.hug.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  4/30 20:20:04 2020
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 1000
int dp[MAX_N + 5][MAX_N + 5];
string s1, s2;

int main() {
    cin >> s1 >> s2;
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            if (s1[i - 1] - s2[j - 1]) continue;
            dp[i][j] = dp[i - 1][j - 1] + 1;
        }
    }
    cout << dp[s1.size()][s2.size()] << endl;
    return 0;
}
