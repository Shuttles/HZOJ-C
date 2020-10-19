/*************************************************************************
	> File Name: 389.czy.cpp
	> Author: 
	> Mail: 
	> Created Time: 一 10/19 21:46:07 2020
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_M 100000

int n, m, max_interval;
int x[MAX_M + 5], arr[MAX_M + 5];

int is_succ(int len);
int bs();

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> x[i];
        arr[x[i]] = 1;
        if (i == 1) continue;
        int temp = x[i] - x[i - 1];
        max_interval = max(max_interval, temp);
    }
    cout << bs() << endl;
    return 0;
}

int is_succ(int len) {
    for (int i = 1; i <= ) 
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
