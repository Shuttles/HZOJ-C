/*************************************************************************
	> File Name: 46.czy.4.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2022年03月27日 星期日 16时23分09秒
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
#include <string.h>
#include <vector>
using namespace std;

//dp[i] 前i位组成的字符串，最少分成几段，xxx
//dp[i] = min(dp[j]) + 1     j<i && j+1~i组成回文串
//ans = dp[n] - 1
//dp[1] = 1
#define MAX_N 500000
#define INF 0x3f
string str;
int dp[MAX_N + 5];

void input() {
    cin >> str;
    str = " " + str;
    memset(dp, INF,sizeof(dp));
    return ;
}

bool isPalindrome(string s, int l, int r) {
    if (l > r) return false;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

int output() {
    dp[0] = 0;//一定要注意dp[0]，非常重要！！！
    dp[1] = 1;
    for (int i = 2; i < str.size(); i++) {
        dp[i] = dp[i - 1] + 1;//bad situation
        for (int j = 0; j < i; j++) {//如果j=1就是回文，那就会涉及dp[0]
            if (isPalindrome(str, j + 1, i) == false) continue;
            dp[i] = min(dp[i], dp[j] + 1);
        }
    }
    return dp[str.size() - 1] - 1;
}

int main() {
    input();
    cout << output() << endl;
    return 0;
}
