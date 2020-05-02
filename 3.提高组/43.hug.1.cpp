/*************************************************************************
	> File Name: 43.hug.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  4/30 18:33:04 2020
 ************************************************************************/

//dp[i][j]定义为从(i, j)这个位置到最下面一层的最大路径和
//dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1])
#include<iostream>
using namespace std;

#define MAX_N 1000

int dp[MAX_N + 5][MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> dp[i][j];
        }
    } 

    for (int i = n - 1; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    cout << dp[1][1] << endl;

    return 0;
}
