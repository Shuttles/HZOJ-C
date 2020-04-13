/*************************************************************************
	> File Name: 382.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2020年04月05日 星期日 22时51分20秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    queue<int> q;
    //先把所有人入队列
    for (int i = 0; i < n; i++) {
        q.push(i + 1);
    }

    while (q.size() > 1) {//就是当剩下的人多于1一个人时一直循环
        int cnt = m - 1;
        while (cnt--) {
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }

    cout << q.front() << endl;
    return 0;
}
