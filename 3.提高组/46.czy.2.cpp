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

#define MAX_N 500000
string str;
int dp[MAX_N + 5];

//hug实现的is_palindromic
//高下立判啊！
bool is_palindromic(string &s, int start, int end) {
    int i = start, j = end;
    while (i < j) {
        if (str[i++] - str[j--]) return false;
    }
    return true;
}

int main() {
    cin >> str;
    str = " " + str;
    dp[0] = 0;//为特殊情况而设定的
    dp[1] = 1;

    //特殊情况：gvgzcdwujv
    //gvg的时候就是切0刀，分1段      这时候就看出来这种状态定义的优秀之处了！
    for (int i = 2; i <= str.size() - 1; i++) {
        //初始化dp数组
        dp[i] = dp[i - 1] + 1;
        for (int j = 0; j < i; j++) {
            if (!is_palindromic(str, j + 1, i)) continue;
            dp[i] = min(dp[i], dp[j] + 1);
        }
        //printf("dp[%d] = %d\n", i, dp[i]);
    }

    cout << dp[str.size() - 1] - 1 << endl;
    return 0;
}
