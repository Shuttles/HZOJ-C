/*************************************************************************
	> File Name: 397.僵尸来袭.cpp
	> Author: 
	> Mail: 
	> Created Time: 六 10/10 16:32:05 2020
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 100

int n, m, ans, area;
char mmap[MAX_N + 5][MAX_N + 5];
int used[MAX_N + 5][MAX_N + 5];
int dnext[4][2] = {
    {1, 0}, {-1, 0}, 
    {0, 1}, {0, -1}
};

struct node {
    int x, y;
    node(int nx, int ny) : x(nx), y(ny) {

    }
};
queue<node> q;

void dfs(int, int);

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '1') {
                q.push(node(i, j));
            }
        }
    }

    while (!q.empty()) {
        node temp = q.front();
        q.pop();
        if (used[temp.x][temp.y]) continue;//已走过，就不必走了

        used[temp.x][temp.y] = 1;
        area = 1;
        dfs(temp.x, temp.y);
        ans = max(ans, area);
    }
    cout << ans << endl;
    return 0;
}

void dfs(int x,int y) {
    for (int i = 0; i < 4; i++) {
        int dx = x + dnext[i][0];
        int dy = y + dnext[i][1];
        if (dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
        if (mmap[dx][dy] == '0') continue;
        if (used[dx][dy]) continue;

        area += 1;
        used[dx][dy] = 1;
        dfs(dx, dy);
    }
    return ;
}
