#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define ind(i, j) ((i) * (m) + (j) + 1)
#define MAX_N 1000000

int mmap[1005][1005];

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
    int T;
    cin >> T;
    while (T--) {
        int n, m, q;
        cin >> n >> m >> q;
        UnionSet *u = init_UnionSet(MAX_N);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> mmap[i][j];
                if (mmap[i][j] == 1) continue;/*不可通行*/
                if (i > 1 && mmap[i - 1][j] == 0) merge(u, ind(i, j), ind(i - 1, j));
                if (j > 1 && mmap[i][j - 1] == 0) merge(u, ind(i, j), ind(i, j - 1));
            }
        }

        for (int i = 0; i < q; i++) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1 += 1;
            y1 += 1;
            x2 += 1;
            y2 += 1;
            if (mmap[x1][y1] == 1 || mmap[x2][y2] == 1) {
                cout << 0 << endl;
                continue;
            }
            int f1 = find(u, ind(x1, y1)), f2 = find(u, ind(x2, y2));
            if (f1 != f2) cout << 0 << endl;
            else cout << 1 << endl;
        }       
    }
    return 0;
}
