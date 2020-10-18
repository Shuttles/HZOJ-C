/*************************************************************************
	> File Name: 390.czy.cpp
	> Author: 
	> Mail: 
	> Created Time: 日 10/18 17:33:45 2020
 ************************************************************************/
//111110000求最后一个1
//切不出的情况是 全是0
#include <iostream>
#include <algorithm>
#include <cinttypes>
using namespace std;

#define MAX_N 100000
#define MAX_M 100000000
int n, max_x = INT32_MIN;
int x[MAX_N + 5];

int bs(int m);
int func(int len, int m);

int main() {
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        max_x = max(max_x, x[i]);
    }
    
    cout << bs(m) << endl;
    

    return 0;
}

int func(int len, int m) {//判断如果每根原木长度为len，能否切出m段,这是二分答案的难点！
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += x[i] / len;
        if (cnt >= m) {
            return 1;
        } 
    }
    return 0;
}

int bs(int m) {
    int head = 0, tail = max_x;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (func(mid, m)) head = mid;
        else tail = mid - 1;
    }
    return head;
}
