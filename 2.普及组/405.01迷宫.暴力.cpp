/*************************************************************************
	> File Name: 404.01迷宫简易版.cpp
	> Author: 
	> Mail: 
	> Created Time: 五 10/ 9 21:34:00 2020
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 3000

int n, m, k, sx, sy, ans = 1;
char pre[MAX_N + 5][MAX_N + 5];
int mmap[MAX_N + 5][MAX_N + 5];
bool used[MAX_N + 5][MAX_N + 5];
int dnext[4][2] = {
    {-1, 0}, {0, 1}, 
    {1, 0}, {0, -1}
};

void dfs(int, int, int);

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> pre[i][j];
            mmap[i][j] = pre[i][j] - '0';
        }
    }
    while (k--) {
        cin >> sx >> sy;
        sx -= 1, sy -= 1;
        used[sx][sy] = true;                   //别忘了把起点锁上！！！
        int flag = (mmap[sx][sy] == 0 ? 1 : 0);//flag为下一步能走的格
        dfs(sx, sy, flag);
        cout << ans << endl;
        memset(used, 0, sizeof(used));
        ans = 1;
    }
    return 0;
}

void dfs(int x, int y, int flag) {
    for (int i = 0; i < 4; i++) {
        int dx = x + dnext[i][0];
        int dy = y + dnext[i][1];
        if (used[dx][dy] == true) continue;
        if (mmap[dx][dy] != flag) continue;
        if (dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
        used[dx][dy] = true;
        ans += 1;
        dfs(dx, dy, (mmap[dx][dy] == 0 ? 1 : 0));
        //不用解锁
    }
    return ;
}
