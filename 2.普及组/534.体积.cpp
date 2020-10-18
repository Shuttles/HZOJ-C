/*************************************************************************
	> File Name: 534.体积.cpp
	> Author: 
	> Mail: 
	> Created Time: 日 10/18 15:05:27 2020
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 20
#define MAX_V 1000

int v[MAX_N + 5], used[MAX_N + 5], mark[MAX_V + 5] = {1};
int arr[MAX_N + 5];//存放体积组合数
int ans, n, ind;//ind记录上一层的数字在v数组中的下标

void dfs(int depth);

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort(v, v + n);
    dfs(1);
    cout << ans << endl;
    return 0;
}

void dfs(int depth) {
    int ret = 0;                             //根据条件剪枝
    for (int i = 1; i < depth; i++) {
        ret += arr[i];
    }
    if (mark[ret] == 0) {
        ans += 1;
        mark[ret] = 1;
    } 

    if (depth > n) return ;
    
    
    int start = 1;
    if (depth > 1) start = ind;
    for (int i = start ;i <= n; i++) {
        if (used[i]) continue;
        used[i] = 1;
        arr[depth] = v[i];
        ind = i;
        dfs(depth + 1);
        used[i] = 0;
    }
    return ;
}
