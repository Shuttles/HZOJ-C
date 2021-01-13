/*************************************************************************
	> File Name: 44.czy.1.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年01月13日 星期三 11时03分10秒
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

//dp[i] 以num[i]为结尾的最长上升子序列的长度
//dp[i] = max(dp[j]) + 1 | j<i, num[j]<num[i]

#define MAX_N 1000000
int num[MAX_N + 5], dp[MAX_N + 5];

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        dp[i] = 1;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (num[j] >= num[i]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
