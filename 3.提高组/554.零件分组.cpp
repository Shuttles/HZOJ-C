/*************************************************************************
	> File Name: 554.零件分组.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  4/14 17:16:59 2020
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define MAX_N 1000

struct Part {
    int x;
    int y;
} num[MAX_N + 5];

int len[MAX_N + 5];
int ans = 0;


bool cmp(const Part &a, const Part &b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}



int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i].x >> num[i].y;
    }
    sort(num + 1, num + n + 1, cmp);
    ans += 1;
    len[ans] = num[1].y;
    for (int i = 2; i <= n; i++) {
        int temp = 0;
        for (int j = 1; j <= ans; j++) {
            if (len[j] > num[i].y) continue;
            if (!temp) temp = j;
            else if (len[temp] < len[j]) {
                temp = j;
            }
        }
        if (!temp) {
            ans += 1;
            len[ans] = num[i].y;
        } else {
            len[temp] = num[i].y;
        }
    }
    printf("%d\n", ans);
    return 0;
}
