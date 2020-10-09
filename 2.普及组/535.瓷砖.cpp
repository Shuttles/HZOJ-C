/*************************************************************************
	> File Name: 535.瓷砖.cpp
	> Author: 
	> Mail: 
	> Created Time: 三 10/ 7 23:36:29 2020
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 50
char mmap[MAX_N + 5][MAX_N + 5];
bool used[MAX_N + 5][MAX_N + 5];
int w, h, sx, sy, ans;
int dnext[4][2] = {
    {0, 1}, {0, -1},
    {1, 0}, {-1, 0}
};


void dfs(int, int);

int main() {
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '@') {
                sx = i, sy = j;
                printf("起点！\n");
            }
        }
    }

    dfs(sx, sy);
    cout << ans << endl;
    return 0;
}

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int dx = x + dnext[i][0];
        int dy = y + dnext[i][1];
        if (used[dx][dy] == true) continue;
        if (mmap[dx][dy] == '#') continue;
        if (dx < 0 || dx > w || dy < 0 || dy > h) continue;
        used[dx][dy] = true;
        printf("ans + 1!\n");
        ans += 1;
        dfs(dx, dy);
        //不用解锁
    }
    return ;
}
