/*************************************************************************
	> File Name: 80.czy.bfs.cpp
	> Author: 
	> Mail: 
	> Created Time: 五 10/16 21:31:48 2020
 ************************************************************************/
//广搜模板题
#include <iostream>
#include <queue>
using namespace std;

#define MAX_N 500

struct node {
    int x, y, step;//我到这个点走了几步
};

int n, m;
char mmap[MAX_N + 5][MAX_N + 5];
queue<node> q;
int dnext[4][2] = {
    {-1, 0}, {0, 1}, 
    {1, 0}, {0, -1}
};

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 's') {
                node temp;
                temp.x = i, temp.y = j;
                temp.step = 0;
                q.push(temp);
            }
        }
    }
    
    //bfs
    while (!q.empty()) {
        node temp = q.front();
        q.pop();
    
        for (int i = 0; i < 4; i++) {
            int dx = temp.x + dnext[i][0];
            int dy = temp.y + dnext[i][1];
            if (dx < 0 || dx >= n || dy < 0 || dy >= m) continue;

            if (mmap[dx][dy] == 'g') {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if (mmap[dx][dy] == '.') {
                mmap[dx][dy] = 0;
                node temp1;
                temp1.x = dx, temp1.y = dy;
                temp1.step = temp.step + 1;
                q.push(temp1);
            }
        }

    }
    cout << "No" << endl;
    return 0;
}
