// dp[i]:以i为结尾的最大子段和
// dp[i] = dp[i - 1] + num[i]    if(dp[i - 1] > 0)
//       = num[i]                if(dp[i - 1] <= 0)
// dp[i] = num[i]
#include <iostream>
using namespace std;
#define MAX_N 10000
int n;
long long num[MAX_N + 5], dp[MAX_N + 5];

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }
    return;
}

void output()
{
    dp[1] = num[1]; // 这个很重要！！！不能初始化为0！！否则全是负数就不好使了！！
    long long ans = dp[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i] = num[i];
        if (dp[i - 1] > 0)
        {
            dp[i] += dp[i - 1];
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return;
}

int main()
{
    input();
    output();
    return 0;
}