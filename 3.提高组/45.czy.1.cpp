/*************************************************************************
	> File Name: 45.czy.1.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年01月13日 星期三 11时27分35秒
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

//dp[i][j] str1取前i位 str2取前j位，它们的最长公共子序列长度
//dp[i][j] = dp[i - 1][j - 1] + 1    str1[i]==str2[j]
//           max(dp[i - 1][j], dp[i][j - 1])     str1[i]!=str2[j]

#define MAX_N 1000
int dp[MAX_N + 5][MAX_N + 5];
string str1, str2;

int main() {
    cin >> str1 >> str2;
    str1 = " " + str1; //妙啊
    str2 = " " + str2;
    for (int i = 1; i <= str1.size() - 1; i++) {
        for (int j = 1; j <= str2.size() - 1; j++) {
            if (str1[i] == str2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[str1.size() - 1][str2.size() - 1] << endl;
    return 0;
}
