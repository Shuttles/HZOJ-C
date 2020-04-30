/*************************************************************************
	> File Name: 264.最大矩形面积.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  4/30 14:08:11 2020
 ************************************************************************/

#include<iostream>
#include <cinttypes>
using namespace std;

#define MAX_N 100000

int64_t arr[MAX_N + 5], s[MAX_N + 5], l[MAX_N + 5], r[MAX_N + 5];
int top = -1;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    arr[0] = arr[n + 1] = -1;//在两边挖坑

    /*找出每个矩形左边第一个高度比他小的矩形下标*/
    s[top = 0] = 0; 
    for (int i = 1; i <= n; i++) {
        while (arr[s[top]] >= arr[i]) --top;
        l[i] = s[top];
        s[++top] = i;
    }

    /*找出每个矩形右边第一个高度比他小的矩形下标*/
    s[top = 0] = n + 1;
    for (int i = n; i > 0; i--) {
        while (arr[s[top]] >= arr[i]) --top;
        r[i] = s[top];
        s[++top] = i;
    }


    /*计算结果*/
    int64_t ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, (arr[i] * (r[i] - l[i] - 1)));
    }
    cout << ans << endl;

    return 0;
}
