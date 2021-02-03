/*************************************************************************
	> File Name: 46.切割回文.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年01月13日 星期三 15时25分01秒
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


//dp[i] 以str[i]作为结尾，最少分成多少段...
//dp[i] = min(dp[j]) + 1   |  j<i, j+1~i是回文串
//
//优化：转移过程的优化
//维护一个mark[], mark[i]是以i为结尾的回文串的首部下标
//那么转移的时候的时间复杂度就和回文串的数量有关了,　和字符串长度就没什么关系了
//
//如何获取回文串？
//以每个位置作为回文串的中心点，向周围进行扩展，扩展出字符串

#define MAX_N 500000
string str;
int dp[MAX_N + 5];

vector<int> mark[MAX_N + 5];

int expand(string &s, int i, int j) {
    while (s[i] == s[j]) {
        mark[j].push_back(i);
        --i, ++j;
        if (i < 1 || j > s.size() - 1) break;
    }
    return 1;
}

int main() {
    cin >> str;
    str = " " + str;
    dp[0] = 0;//为特殊情况而设定的
    dp[1] = 1;

    //初始化mark[]
    for (int i = 1; str[i]; i++) {
        expand(str, i, i);//扩展出来的是拥有奇数个字符的回文串
        (i + 1 <= (str.size() - 1)) && expand(str, i, i + 1);//偶数个字符
    }

    for (int i = 2; i <= str.size() - 1; i++) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 0; j < mark[i].size(); j++) {
            dp[i] = min(dp[i], dp[mark[i][j] - 1] + 1);
        }
    }

    cout << dp[str.size() - 1] - 1 << endl;
    return 0;
}
