/*************************************************************************
	> File Name: C.滑动窗口.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  5/30 14:01:27 2020
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 300000
int arr[MAX_N + 5], q[MAX_N + 5];
int head, tail;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    for (int i = 1; i <= n; i++) {
        while (head - tail && arr[q[tail - 1]] >= arr[i]) --tail;
        q[tail++] = i;
        if (i - q[head] >= k) head++;
        if (i < k) continue;
        (i == k) || cout << " ";
        cout << arr[q[head]];
    }
    cout << endl;

    head = tail = 0;
    for (int i = 1; i <= n; i++) {
        while (head - tail && arr[q[tail - 1]] <= arr[i]) --tail;
        q[tail++] = i;
        if (i - q[head] >= k) head++;
        if (i < k) continue;
        (i == k) || cout << " ";
        cout << arr[q[head]];
    }
    cout << endl;

    return 0;
}
