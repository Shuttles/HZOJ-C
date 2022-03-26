/*************************************************************************
	> File Name: 45.czy.2.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2022年03月26日 星期六 22时06分57秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

//dp[i][j] = dp[i - 1][j - 1] + 1    if s1[i]==s2[j]
//           max(dp[i][j - 1], dp[i - 1][j])    if s1[i]!=s2[j]
//ans = dp[n][m]
#define MAX_N 1000
string s1, s2;
int dp[MAX_N + 5][MAX_N + 5];

void input() {
    cin >> s1 >> s2;
    s1 = " " + s1;
    s2 = " " + s2;
    return ;
}

int output() {
    int ans = 0;
    for (int i = 1; i < s1.size(); i++) {
        for (int j = 1; j < s2.size(); j++) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[s1.size() - 1][s2.size() - 1];
}

int main() {
    input();
    cout << output() << endl;
    return 0;
}
