/*************************************************************************
	> File Name: 235.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 二 10/ 6 22:20:52 2020
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 10

int num[MAX_N + 5], cnt = 0;//cnt是计数器，表示存几个数了，表示每一层存几个数，num数组存答案，num[i]表示每一层
int n;

void output() {
    for (int i = 0; i < cnt; i++) {
        if (i) cout << " ";
        cout << num[i];
    }
    cout << endl;
}

void func(int s) {
    for (int i = s; i <= n; i++) {
        num[cnt++] = i;
        output();
        func(i + 1);//进入下一层
        cnt--;//回溯
    }
    return ;
}

int main() {
    cin >> n;
    func(1);
    return 0;
}
