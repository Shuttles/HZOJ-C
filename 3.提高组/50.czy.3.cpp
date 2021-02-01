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
//
//最终的优化是状态定义的优化
//当发现某个自变量与因变量直接存在相关性的时候，两者即可对调
//dp[i][j] = k　重定义成 dp[i][k] = j 表示i个鸡蛋扔k次，最多测多少层楼
//m的值域太大，存不下，而k的值域较小，可以存下
//dp[i][k] = dp[i - 1][k - 1] + dp[i][k - 1] + 1
#define MAX_N 32
#define MAX_K 50000
long long dp[MAX_N + 5][MAX_K + 5];

long long solve(int n, int m) {
    if (n == 1) return m;
    for (int i = 1; i <= MAX_K; i++) dp[1][i] = i;
    for (int i = 2; i <= n; i++) {
        for (int k = 1; k <= MAX_K; k++) {
            dp[i][k] = dp[i - 1][k - 1] + dp[i][k - 1] + 1;//其实可以改成一维的
        }
    }
    
    /*
    printf("n = %d\n", n);
    for (int i = 1; i <= 15; i++) {
        printf("k = %d, dp = %lld\n", i, dp[n][i]);
    }
    */

    int k = 1;
    while (dp[n][k] < m) ++k;
    return k;
}


int main() {
    int n, m;
    cin >> n >> m;
    cout << solve(n, m) << endl;
    return 0;
}
