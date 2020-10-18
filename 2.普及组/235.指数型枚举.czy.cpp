/*************************************************************************
	> File Name: 235.czy.cpp
	> Author: 
	> Mail: 
	> Created Time: 六 10/10 17:07:54 2020
 ************************************************************************/

//其实就是组合数
//只不过每次成功选择一次就输出一次！
#include <iostream>
using namespace std;

#define MAX_N 10
int num[MAX_N + 5], used[MAX_N + 5];
int n, cnt;

void dfs(int);
void output();

int main() {
    cin >> n;
    dfs(0);
    return 0;
}

void output() {
    for (int i = 0; i < cnt; i++) {
        i && printf(" ");
        cout << num[i];
    }
    cout << endl;
}

void dfs(int depth) {
    int start = 1;
    if (depth > 0) start = num[depth - 1] + 1;
    for (int i = start; i <= n; i++) {
        if (used[i]) continue;
        
        cnt++;
        used[i] = 1;
        num[depth] = i;
        output();
        dfs(depth + 1);
        used[i] = 0;
        cnt--;
    }
    return ;
}
