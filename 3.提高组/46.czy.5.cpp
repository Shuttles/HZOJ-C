// dp[i]: 截止第i位，最少分成几段，使得每一部分都是回文串
// dp[i] = min(dp[j]) + 1, 1<=j<i && ispanlindrome(j+1,i)
// dp[0] = 0
// dp[1] = 1
// 详细解析见46.czy.4.cpp
#include <iostream>
#include <string>
using namespace std;
#define MAX_N 500000
// #define INF 0x3f

int dp[MAX_N + 5];
string str;

void input()
{
    cin >> str;
    str = " " + str;
    // memset(dp, INF, sizeof(dp));
    return;
}

bool isPalindrome(int l, int r)
{
    while (l < r)
    {
        if (str[l] != str[r])
        {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

void output()
{
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < str.size(); i++)
    {
        dp[i] = dp[i - 1] + 1;
        for (int j = 0; j < i; j++)
        {
            if (isPalindrome(j + 1, i))
            {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    cout << dp[str.size() - 1] - 1 << endl;
    return;
}

int main()
{
    input();
    output();
    return 0;
}