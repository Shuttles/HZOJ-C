/*************************************************************************
	> File Name: 50.扔鸡蛋.czy.1.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年01月14日 星期四 10时37分58秒
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

//dp[i][j] 用i个鸡蛋，测j层楼，最坏情况下最少测多少次，可以测出鸡蛋的硬度
//dp[i][j] = min(max(dp[i - 1][k - 1] + 1, dp[i][j - k] + 1))   |  1<=k<=j
//边界条件
//dp[1][m] = m ！！！！只能从下往上测！！

//题目要求是MAX_M 2^31 但是开不出来这么大数组，所以能开多少是多少
//由此可见，最终应该还需要优化
//而且时间复杂度为O(n * m^2)，比较慢，HZOJ只能得30分
//
//这种方法是转移过程的优化，通过寻找ｋ与dp[i - 1][k - 1]、dp[i][j - k]的关系可以得到
//拐点，也就是最优的转移K值，一定发生在两者的交点处，并且是递增的
//从而可以去掉第三层循环
//优化后的时间复杂度为O(n * m)   HZOJ可以得60分
//其实这种方法的正确性我一直不是很懂。。。。
#define MAX_N 32
#define MAX_M 1000000 
int dp[MAX_N + 5][MAX_M + 5];


int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) dp[1][i] = i;

    for (int i = 2; i <= n; i++) {
        int k = 1;//k是那个拐点
        for (int j = 1; j <= m; j++) {
            while (k <= j && dp[i - 1][k - 1] < dp[i][j - k]) ++k;
            dp[i][j] = max(dp[i - 1][k - 1], dp[i][j - k]) + 1;//其实可以不用max????
        }
    }
    cout << dp[n][m] << endl;

    /*
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n"); 
    }*/

    return 0;
}
