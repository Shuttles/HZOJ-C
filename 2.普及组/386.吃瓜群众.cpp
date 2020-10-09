/*************************************************************************
	> File Name: 386.吃瓜群众.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2020年09月22日 星期二 18时39分50秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

#define MAX_N 100000

struct node {
    int num, cnt;
};

bool cmp(node a, node b) {
    return a.num < b.num;
}

node wm[MAX_N + 5];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> wm[i].num;
        wm[i].cnt = i + 1;
    }
    sort(wm, wm + n, cmp);
    for (int i = 0; i < m; i++) {
        int t, l = 0, r = n - 1, flag = 0;
        cin >> t;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (wm[mid].num == t) {
                cout << wm[mid].cnt << endl;
                flag = 1;
                break;
            }
            if (wm[mid].num < t) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (flag == 0) {
            cout << 0 << endl;
        }
    }
    
    return 0;
}
