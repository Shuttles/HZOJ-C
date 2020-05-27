/*************************************************************************
	> File Name: 271.czy.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  5/27 08:44:58 2020
 ************************************************************************/

//单调队列就是用来维护区间最大最小值的！
#include <iostream>
using namespace std;

#define MAX_N 300000
int arr[MAX_N + 6], q[MAX_N + 6];
int head = 0, tail = 0;


int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    /*处理区间最小值, 维护一个单调递增队列*/
    for (int i = 1; i < k; i++) {
        while (head - tail && arr[q[tail - 1]] >= arr[i]) --tail;
        q[tail++] = i;
    }
    for (int i = k; i <= n; i++) {
        while (head - tail && arr[q[tail - 1]] >= arr[i]) --tail;
        q[tail++] = i;
        /*判断头部元素是否过期*/
        if (q[head] <= i - k) head++;
        (i == k) || cout << " ";
        cout << arr[q[head]];
    }

    cout << endl;

    head = tail = 0;
    /*处理区间最大值, 维护一个单调递减队列*/
    for (int i = 1; i < k; i++) {
        while (head - tail && arr[q[tail - 1]] <= arr[i]) --tail;
        q[tail++] = i;
    }
    for (int i = k; i <= n; i++) {
        while (head - tail && arr[q[tail - 1]] <= arr[i]) --tail;
        q[tail++] = i;
        /*判断头部元素是否过期*/
        if (q[head] <= i - k) head++;
        (i == k) || cout << " ";
        cout << arr[q[head]];
    }

    cout << endl;
    return 0;
}
