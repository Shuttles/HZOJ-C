// dp[i]: 以i为结尾，打完的最小磨损值
// dp[i] = min(dp[j] + loss(j+1, i))  j<i
// dp[0] = 0;
// ans=dp[n]
#include <iostream>
using namespace std;
#define MAX_N 1000000
#define MAX_M 10000

int n, m;
int c[MAX_N + 5];
int dp[MAX_N + 5];

void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    return;
}

int loss(int l, int r)
{
    int ans = 0;
    for (int i = l; i <= r; i++)
    {
        ans += c[i];
    }
    ans = ans * ans;
    ans += m;
    return ans;
}

void output()
{
    for (int i = 1; i <= n; i++)
    {
        dp[i] = loss(1, i);
        for (int j = 0; j < i; j++)
        {
            dp[i] = min(dp[i], dp[j] + loss(j + 1, i));
        }
    }
    cout << dp[n] << endl;
    return;
}

int main()
{
    input();
    output();
    return 0;
}