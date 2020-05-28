/*************************************************************************
	> File Name: 264.czy.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  5/28 20:17:56 2020
 ************************************************************************/

#include <iostream>
#include <cinttypes>
using namespace std;

#define MAX_N 100000
int64_t arr[MAX_N + 5], s[MAX_N + 5], top = -1;
int r[MAX_N + 5], l[MAX_N + 5];//r[i]表示第i个矩形右边第一个小于他的矩形高度


int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    arr[0] = arr[n + 1] = -1;/*设置两个边界值*/

    /*计算l数组*/
    /*维护一个单调递增栈*/
    s[top = 0] = 0;
    for (int i = 1; i <= n; i++) {
        while (arr[s[top]] >= arr[i]) top--;
        l[i] = s[top];
        s[++top] = i;
    }

    /*计算r数组*/
    s[top = 0] = n + 1;
    for (int i = n; i >= 1; i--) {
        while (arr[s[top]] >= arr[i]) top--;
        r[i] = s[top];
        s[++top] = i;
    }
    
    int64_t ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, arr[i] * (r[i] - l[i] - 1));
    }

    cout << ans << endl;
    return 0;
}
