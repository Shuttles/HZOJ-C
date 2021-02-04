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
#include <cstring>
#include <vector>
using namespace std;

//dp[i] 以num[i]为结尾的最长上升子序列的长度
//dp[i] = max(dp[j]) + 1 | j<i, num[j]<num[i]
//
//优化：转移过程的优化　维护一个len[]　记录每一种长度序列尾部最小值
//dp[i] = k + 1 | k是len[]中最后一个小于num[i]的位置
//dp[i]得到之后要更新len[k + 1] = num[i]

#define MAX_N 1000000
#define INF 0x3f
int num[MAX_N + 5], dp[MAX_N + 5], len[MAX_N + 5];
//其实这个num[]并不需要！！

//11111000找最后一个1
int binary_search(int *arr, int n, int target) {
    int head = -1, tail = n, mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (arr[mid] < target) head = mid;
        else tail = mid - 1;
    }
    return head;
}

int main() {
    int n, ans = 0;
    cin >> n;

    memset(len, INF, sizeof(len));
    len[0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        dp[i] = 1;
    }
    
    for (int i = 1; i <= n; i++) {
        dp[i] = binary_search(len, ans + 1, num[i]) + 1;//这个ans + 1传得妙啊！
        len[dp[i]] = num[i];
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
