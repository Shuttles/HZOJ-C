/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  3/12 12:16:42 2020
 ************************************************************************/

#include<iostream>
using namespace std;
#include <cinttypes>
#define MAX_N 1000

char mmap[MAX_N + 5][MAX_N + 5];
int mark[MAX_N + 5][MAX_N + 5];
int n, m, sx, sy, p, q;
int min_steps = INT32_MAX;
int dnext[4][2] = {
    {0, 1}, {1, 0},
    {0, -1}, {-1, 0}
};
void dfs(int x, int y, int step);

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 's') sx = i, sy = j;
            if (mmap[i][j] == 'g') p = i, q = j;
        }
    }
    //cin >> sx >> sy >> p >> q;
    mark[sx][sy] = 1;
    dfs(sx, sy, 0);
    if (min_steps == INT32_MAX) {
        printf("No\n");
    } else {
        printf("%d\n", min_steps);
    }
    return 0;
}

void dfs(int x, int y, int step) {
    if (x == p && y == q) {
        if (step < min_steps) min_steps = step;
        return ;
    }
    for (int i = 0; i < 4; i++) {
        int dx = x + dnext[i][0];
        int dy = y + dnext[i][1];
        if (dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
        if (mmap[dx][dy] == '#' || mark[dx][dy] == 1) continue;
        mark[dx][dy] = 1;
        dfs(dx, dy, step + 1);
        mark[dx][dy] = 0;
    }
    return ;
}
