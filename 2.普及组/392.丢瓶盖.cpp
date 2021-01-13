/*************************************************************************
	> File Name: 392.丢瓶盖.cpp
	> Author: 
	> Mail: 
	> Created Time: 二 10/20 22:14:10 2020
 ************************************************************************/
//此题和389暴躁的程序员是一模一样的！！
#include <iostream>
#include <algorithm>
#include <cinttypes>
using namespace std;

#define MAX_N 100000000
int a, b, min_ind = INT32_MAX, max_ind, max_interval;
int x, arr[MAX_N + 5];//arr[i] = 1 表示这个地方有瓶盖

int is_succ(int interval);//语义信息：最近距离为interval时是否可以
int bs();

int main() {
    cin >> a >> b;
    for (int i = 1; i <= a; i++) {
        cin >> x;
        arr[x] = 1;
        min_ind = min(min_ind, x);
        max_ind = max(max_ind, x);
    }
    max_interval = max_ind - min_ind;
    cout << bs() << endl;
    return 0;
}

int is_succ(int interval) {
    int cnt = 0;
    for (int i = 1; i <= max_ind; ) {
        if (!arr[i]) {
            i++;
            continue;
        }
        cnt += 1;
        i += interval;
        if (cnt >= b) return 1;
    }
    return 0;
}

int bs() {
    int head = 1, tail = max_interval;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (is_succ(mid)) head = mid;
        else tail = mid - 1;
    }
    return head;
}
