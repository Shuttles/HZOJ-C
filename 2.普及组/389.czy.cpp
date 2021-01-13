/*************************************************************************
	> File Name: 389.czy.cpp
	> Author: 
	> Mail: 
	> Created Time: 一 10/19 21:46:07 2020
 ************************************************************************/

//本质：11111000找最后一个1
#include <iostream>
#include <algorithm>
#include <cinttypes>
using namespace std;
#define MAX_M 100000
#define MAX_X 1000000000

int n, m, max_interval, min_ind = INT32_MAX, max_ind;
int x, arr[MAX_X + 5];//arr的下标表示座位号，arr[i]为1表示空余

int is_succ(int interval);//语义信息：最小间隔为interval是否可以
int bs();

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> x;
        arr[x] = 1;//表示有空位

        min_ind = min(min_ind, x);
        max_ind = max(max_ind, x);
    }
    max_interval = max_ind - min_ind;
    cout << bs() << endl;
    return 0;
}

int is_succ(int interval) {
    int cnt = 0;
    for (int i = 1; i <= max_ind;) {
        if (!arr[i]) {
            i += 1;
            continue;//i座没有空出来
        }
        cnt += 1;
        i += interval;
        if (cnt >= n) {
            //printf("最近距离为%d是可以的!\n", interval);
            return 1;
        }
    }
    //printf("最近距离为%d是不可以的!\n", interval);
    return 0;
}

int bs() {
    int head = 0, tail = max_interval;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (is_succ(mid)) head = mid;
        else tail = mid - 1;
    }
    return head;
}
