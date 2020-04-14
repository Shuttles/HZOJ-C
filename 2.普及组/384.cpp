/*************************************************************************
	> File Name: 384.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  4/ 6 10:16:09 2020
 ************************************************************************/

#include <iostream>
#include <queue>
<<<<<<< HEAD
=======
#include <cstdio>
#include <cstdlib>
>>>>>>> 71d5ebf12b16450c550f4b25612a0e1bc2631926
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
<<<<<<< HEAD
=======
    //注意入队顺序！！！
>>>>>>> 71d5ebf12b16450c550f4b25612a0e1bc2631926
    for (int i = x; i <= n; i++) {
        q.push(i);
    }
    for (int i = 1; i < x; i++) {
        q.push(i);
    }
    
    while (q.size() > 1) {
        if (AboutSeven(t)) {
<<<<<<< HEAD
            q.pop();
        } else {
=======
            //如果符合要求，就淘汰(出队)
            q.pop();
        } else {
            //否则去队尾
>>>>>>> 71d5ebf12b16450c550f4b25612a0e1bc2631926
            q.push(q.front());
            q.pop();
        }
        t += 1;
    }
    cout << q.front() << endl;
    return 0;
}
