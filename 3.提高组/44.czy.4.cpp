/*************************************************************************
	> File Name: 44.czy.4.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2022年03月26日 星期六 17时07分26秒
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
using namespace std;

//dp[i] 以arr[i]作为结尾的上升子序列的长度
#define MAX_N 1000000
#define MAX_NUM 10000
int n;
int arr[MAX_N + 5], dp[MAX_N + 5];
int len[MAX_N + 5];//len[i] 所有长度为i的上升序列中的尾部最小值,可以证明len是单调递增的
//dp[i] = k + 1 |  len[k] < arr[i] < len[k+1]
//也就是说111111000找最后一个1
//每次更新完dp[i]，len[k + 1] = arr[i] 
//ans = max(dp[i])


void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        len[i] = MAX_NUM + 5;
    }
    return ;
}

//111111000找最后一个1
int bs(int l, int r, int target) {
    int head = l - 1, tail = r;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (len[mid] < target) {
            head = mid;
        } else {
            tail = mid - 1;
        }
    }
    return head;//如果全是0，返回的则是l-1
}

void output_len() {
    printf("len[] = ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", len[i]);
    }
    printf("\n");
    return ;
}

int output() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        //output_len();
        int k = bs(1, n, arr[i]);
        //printf("k = %d\n", k);
        dp[i] = k + 1;
        len[k + 1] = arr[i];
        //printf("dp[%d] = %d\n", i, dp[i]);
        ans = max(ans, dp[i]);
    }
    return ans;
}


int main() {
    input();
    cout << output() << endl;
    return 0;
}
