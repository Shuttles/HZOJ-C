/*************************************************************************
	> File Name: 236.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  3/11 19:42:56 2020
 ************************************************************************/

#include<iostream>
using namespace std;

int n, m, num[15], cnt;

void func(int s, int left) {
    if (left == 0) {
        for (int i = 0; i < cnt ; i++) {
            if (i) cout << " ";
            cout << num[i];
        }
        cout << endl;
        return ;
    }
    for (int i = s; i <= n - left + 1; i++) {//不是i <= n,避免无意义的搜索
        num[cnt++] = i;
        func(i + 1, left - 1);
        cnt--;
    }
    return ;
}

int main() {
    cin >> n >> m;
    func(1, m);
    return 0;
}
