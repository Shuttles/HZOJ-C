/*************************************************************************
	> File Name: 235.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  3/11 19:06:42 2020
 ************************************************************************/

#include<iostream>
using namespace std;

int n, num[15],cnt;//cnt是num的计数器，表示num里存了几个数
void p() {
    for (int i = 0; i < cnt; i++) {
        if (i) cout << " ";
        cout << num[i];
    }
    cout << endl;
    return ;
}

void func(int s) {
    for (int i = s; i <= n; i++) {
        num[cnt] = i;
        cnt++;
        p();
        func(i + 1);
        cnt--;//回溯
    }
    return ;
}

int main() {
    cin >> n;
    func(1);
    return 0;
}
