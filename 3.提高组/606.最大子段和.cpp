/*************************************************************************
    > File Name: 7.最大自序和.cpp
    > Author: 少年宇
    > Mail:
    > Created Time: 2021年02月22日 星期一 15时47分44秒
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
#include <cinttypes>
using namespace std;

// dp[i] 表示以第i位作为结尾的最大子序和的值
// dp[i] = dp[i - 1] + num[i] (if dp[i - 1] > 0)
//       = num[i] (if dp[i - 1] <= 0)
// dp[0] = 0

#define MAX_N 100000
int n;
int num[MAX_N + 5];
long long dp[MAX_N + 5];
int flag = 1; // 如果所有数字均为负数，flag = 1

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        if (num[i] >= 0)
            flag = 0;
    }
    return;
}

void output()
{
    for (int i = 1; i <= n; i++)
    {
        cout << dp[i] << endl;
    }
    return;
}

long long solve()
{
    dp[1] = num[1];
    long long ans = dp[1];
    for (int i = 2; i <= n; i++)
    {
        if (dp[i - 1] <= 0)
        {
            dp[i] = num[i];
        }
        else
        {
            dp[i] = dp[i - 1] + num[i];
        }
        ans = max(ans, dp[i]);
    }

    return ans;
}

int main()
{
    input();
    cout << solve() << endl;
    return 0;
}
