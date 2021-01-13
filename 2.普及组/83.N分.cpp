/*************************************************************************
	> File Name: 83.N分.cpp
	> Author: 
	> Mail: 
	> Created Time: 日 10/18 15:33:09 2020
 ************************************************************************/
//dfs + 剪枝
//剪枝：非递减、m份、和是n
#include <iostream>
using namespace std;
#define MAX_N 100
#define MAX_M 8

int n, m, ans;
int arr[MAX_M + 5];//存放不同分法的结果

void dfs(int depth, int pre, int left);//语义信息：在第depth个格子面前，要填入一个数;上一个格子取的是pre; 要分的数还剩left


int main() {
    cin >> n >> m;
    dfs(1, 1, n);//填第一个格子, 上一个格子取的是1, 要分的数还剩n
    cout << ans << endl;
    return 0;
}


void dfs(int depth, int pre, int left) {
    if (depth > m) {                  //保证了m分
        if (left) return ;             //保证了和是n
        ans += 1;
        return ;
    }

    for (int i = pre; i <= left; i++) {             //保证了非递减
        arr[depth] = i;
        dfs(depth + 1, i, left - i);
    }
    return ;
}
