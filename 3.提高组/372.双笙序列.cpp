/*************************************************************************
	> File Name: 372.双笙序列.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  4/30 14:51:21 2020
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 500000

int a[MAX_N + 5], b[MAX_N + 5];
//遍历到第i位时，单调队列中的元素一定<=i，所以可以拿原数组的前部分当做单调队列！

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int p = 1, top1 = 0, top2 = 0;/*0号元素一定可以构成双笙序列*/
    while (p < n) {
        while (top1 >= 0 && a[top1] >= a[p]) --top1;
        while (top2 >= 0 && b[top2] >= b[p]) --top2;
        if (top1 - top2) break;
        a[++top1] = a[p];
        b[++top2] = b[p];
        p++;
    }
    cout << p << endl;
    return 0;
}
