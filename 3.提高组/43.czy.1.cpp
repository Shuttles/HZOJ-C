/*************************************************************************
	> File Name: 43.czy.1.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年01月13日 星期三 10时29分29秒
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

//dp[i][j] 从底边走到(i, j)能够获得的最大值
//dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + val[i][j]

//其实，可以用dp[][]来存val[][]

#define MAX_N 1000

int val[MAX_N + 5][MAX_N + 5], dp[MAX_N + 5][MAX_N + 5];


int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> val[i][j];
        }
    }
    
    //最后一行
    for (int i = 1; i <= n; i++) {
        dp[n][i] = val[n][i];
    }

    for (int i = n - 1; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + val[i][j];
        }
    }
    cout << dp[1][1] << endl;
    return 0;
}
