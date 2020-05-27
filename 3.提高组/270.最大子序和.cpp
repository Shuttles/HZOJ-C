/*************************************************************************
	> File Name: 270.最大子序和.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  5/27 15:19:22 2020
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 300000
int s[MAX_N + 5], q[MAX_N + 5];
int head, tail;


int main() {
    int n, m, ans;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];/*处理成前缀和数组*/
    }

    //q[tail++] = 0;/*s[0]*/ 到底需不需要将s[0]入队列？？虽然不入也能过这题！
    ans = s[1];
    for (int i = 1; i <= n; i++) {
        while (head - tail && s[q[tail - 1]] >= s[i]) --tail;
        q[tail++] = i;
        if (i - q[head] > m) head++;/*如果区间内维护的元素超过m个，则头部元素过期了，需要出队列*/
        ans = max(ans, s[i] - s[q[head]]);/*选择最大区间和*/
    }
    cout << ans << endl;
    return 0;
}
