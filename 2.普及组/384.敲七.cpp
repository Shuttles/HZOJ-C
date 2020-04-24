/*************************************************************************
	> File Name: 384.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  4/ 6 10:16:09 2020
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>
using namespace std;

bool AboutSeven(int x) {
    if (x % 7 == 0) return true;
    while (x) {
        if (x % 10 == 7) return true;
        x /= 10;
    }
    return false;
}


int main() {
    int n, x, t;
    queue<int> q;
    cin >> n >> x >> t;
    //注意入队顺序！！！
    for (int i = x; i <= n; i++) {
        q.push(i);
    }
    for (int i = 1; i < x; i++) {
        q.push(i);
    }
    
    while (q.size() > 1) {
        if (AboutSeven(t)) {
            q.pop();
        } else {
            //否则去队尾
            q.push(q.front());
            q.pop();
        }
        t += 1;
    }
    cout << q.front() << endl;
    return 0;
}
