/*************************************************************************
	> File Name: 287.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  4/ 6 18:34:41 2020
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;


int main() {
    //记住greater后面要有个空格！否则就是右移操作了！！
    priority_queue<int, vector<int>, greater<int> > q;
    int n, strength = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;
        q.push(temp);
    }
    
    while (q.size() > 1) {
        int temp_sum = 0;
        temp_sum += q.top();
        q.pop();
        temp_sum += q.top();
        q.pop();
        strength += temp_sum;
        q.push(temp_sum);
    }

    cout << strength << endl;

    return 0;
}
