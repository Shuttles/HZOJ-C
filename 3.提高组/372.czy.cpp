/*************************************************************************
	> File Name: 372.czy.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  5/29 08:44:14 2020
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 500000
int a[MAX_N + 5], b[MAX_N + 5];//如果遍历到第i位，那么单调栈里的元素一定小于i个，所以可以将原数组的前半部分当做单调栈
int top_a = -1, top_b = -1;

int main() {
    int n, p = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    
    a[top_a = 0] = 1, b[top_b = 0] = 1;/*两个1号元素一定可以构成双生序列*/
    for (int i = 1; i <= n; i++) {
        while (top_a != -1 && a[a[top_a]] >= a[i]) --top_a;
        a[++top_a] = i;
        while (top_b != -1 && b[b[top_b]] >= b[i]) --top_b;
        b[++top_b] = i;
        if (top_a - top_b) {
            p = i - 1;
            break;
        }

    }
    cout << p << endl;

    return 0;
}
