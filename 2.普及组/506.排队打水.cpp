/*************************************************************************
	> File Name: 506.排队打水.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  5/13 18:26:07 2020
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
    int num, time;
};

bool cmp(node a, node b) {
    return a.time < b.time;
}

int n;
node s[35];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i].time;
        s[i].num = i + 1;
    }
    sort(s, s + n, cmp);
    int ans = 0, now = 0;
    for (int i = 0; i < n; i++) {
        i && cout << " ";
        cout << s[i].num;
        ans += now;
        now += s[i].time;
    }
    printf("\n%.2f\n", (double)ans / n);


    return 0;
}
