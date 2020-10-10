/*************************************************************************
	> File Name: 404.01迷宫简易版.cpp
	> Author: 
	> Mail: 
	> Created Time: 五 10/ 9 21:34:00 2020
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 3000

int n, m, k, ans;
char mmap[MAX_N + 5][MAX_N + 5];
//int mmap[MAX_N + 5][MAX_N + 5];//其实完全可以不用这个图
int used[MAX_N + 5][MAX_N + 5];
int dnext[4][2] = {
    {0, 1}, {1, 0}, 
    {0, -1}, {-1, 0}
};
struct node {
    int x, y;//点坐标
    node(int nx, int ny) : x(nx), y(ny) {

    }
};

queue<node> q;

void dfs(int, int);

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> (&mmap[i][0]);
    }

    //先存起来
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (used[i][j]) continue;             //如果已经标记过，就不走了
            ans = 1;
            used[i][j] = 1;                       //把起点锁上！
            //node temp;
            //temp.x = i, temp.y = j;
            q.push(node(i, j));
            printf("before dfs!\n");
            dfs(i, j);
            printf("after dfs!\n");
            while (!q.empty()) {                  //把这个起点所能走到的所有格都填上
                node temp1 = q.front();
                q.pop();
                //printf("used[%d][%d]！\n", temp1.x, temp1.y);
                used[temp1.x][temp1.y] = ans;
            }
        }
    }

    //询问k次
    for (int i = 0; i < k; i++) {
        int sx, sy;
        cin >> sx >> sy;
        sx -= 1, sy -= 1; 
        cout << used[sx][sy] << endl;
    }

    return 0;
}

void dfs(int x, int y) {
    cout << "in dfs!" << endl;
    for (int i = 0; i < 4; i++) {
        int dx = x + dnext[i][0];
        int dy = y + dnext[i][1];
        if (used[dx][dy]) continue;
        if (mmap[dx][dy] == mmap[x][y]) continue;
        if (dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
        ans += 1;
        used[dx][dy] = 1;
        //node temp2;
        //temp2.x = dx, temp2.y = dy;
        q.push(node(dx, dy));
        //printf("mmap[%d][%d]可走！\n", dx, dy);
        dfs(dx, dy);
        //不用解锁
    }
    return ;
}
