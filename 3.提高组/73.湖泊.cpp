/*************************************************************************
	> File Name: 73.湖泊.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  5/ 9 11:16:32 2020
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define ind(i, j) ((i) * (m) + (j) + 1)
#define MAX_N 1000000

char mmap[1005][1005];

typedef struct UnionSet {
    int *father, *size;
    int n;
} UnionSet;

UnionSet *init_UnionSet(int n) {
    UnionSet *u = (UnionSet *)calloc(1, sizeof(UnionSet));
    u->father = (int *)calloc(n + 1, sizeof(int));
    u->size = (int *)calloc(n + 1, sizeof(int));
    u->n = n;
    for (int i = 1; i <= n; i++) {
        u->father[i] = i;
        u->size[i] = 1;
    }
    return u;
}

void clear_UnionSet(UnionSet *u) {
    if (!u) return;
    free(u->father);
    free(u->size);
    free(u);
    return ;
}

int find(UnionSet *u, int x) {
    return (u->father[x] = (u->father[x] - x ? find(u, u->father[x]) : x));
}

int merge(UnionSet *u, int a, int b) {
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return 0;
    if (u->size[fa] < u->size[fb]) swap(fa, fb);
    u->father[fb] = fa;
    u->size[fa] += u->size[fb];
    return 1;
}



int main() {
    int n, m;
    cin >> n >> m;
    UnionSet *u = init_UnionSet(MAX_N);
    for (int i = 1; i <= n; i++) {
        scanf("%s", &mmap[i][1]);
        for (int j = 1; j <= m; j++) {
            if (mmap[i][j] == 'X') continue;
            if (mmap[i - 1][j] == 'O') merge(u, ind(i, j), ind(i - 1, j));
            if (mmap[i][j - 1] == 'O') merge(u, ind(i, j), ind(i, j - 1));
            /*如果与边界直接或间接相连,不能算作湖泊*/
            if (i == 1 || i == n || j == 1 || j == m) merge(u, ind(i, j), 0);
        }
        getchar();
    }


    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            //printf("%c", mmap[i][j]);
            if (mmap[i][j] == 'X') continue;
            if (find(u, ind(i, j)) - find(u, 0)) ans++;
        }
        //printf("\n");
    }
    cout << ans << endl;
    return 0;
}
