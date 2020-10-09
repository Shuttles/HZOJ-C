/*************************************************************************
	> File Name: 80.小明看电影.cpp
	> Author: 
	> Mail: 
	> Created Time: 二 10/ 6 23:30:32 2020
 ************************************************************************/

#include <iostream>
#include <cinttypes>
using namespace std;

#define MAX_N 500
char mmap[MAX_N + 5][MAX_N + 5], used[MAX_N + 5][MAX_N + 5];
int n, m, sx, sy, ex, ey, min_steps = INT32_MAX;
int dnext[4][2] = {
    {1, 0}, {-1, 0}, 
    {0, 1}, {0, -1}
};

void dfs(int x, int y, int step);

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 's') {
                sx = i, sy = j;
            }
        }
    }
    dfs(sx, sy, 0);
    if (min_steps - INT32_MAX) {
        cout << min_steps << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

void dfs(int x, int y, int step) {
    if (mmap[x][y] == 'g') {
        if (step < min_steps) min_steps = step;
        return ;
    }
    
    for (int i = 0; i <= 3; i++) {
        int dx = x + dnext[i][0];
        int dy = y + dnext[i][1];
        if (dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
        if (mmap[dx][dy] == '#') continue;
        if (used[dx][dy]) continue;
        used[dx][dy] = 1;
        dfs(dx, dy, step + 1);
        used[dx][dy] = 0;
    }
    return ;
}
