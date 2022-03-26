/*************************************************************************
	> File Name: 44.czy.3.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2022年03月24日 星期四 23时30分53秒
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

//dp[i] 以num[i]结尾的最长上升子序列长度
//ans = max(dp[i])
//dp[i] = (max(dp[j]) + 1) if num[j] < num[i]
//dp[1] = 1;
#define MAX_N 1000000
int n;
int arr[MAX_N + 5], dp[MAX_N + 5];

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    return ;
}

int output() {
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (arr[j] >= arr[i]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}


int main() {
    input();
    cout << output() << endl;
    return 0;
}
