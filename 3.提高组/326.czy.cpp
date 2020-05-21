/*************************************************************************
	> File Name: 326.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  5/20 15:27:34 2020
 ************************************************************************/

#include<iostream>
using namespace std;

typedef struct UnionSet {
    int *father, *val, *size;
} UnionSet;

UnionSet *init_UnionSet(int n) {
    UnionSet *u = (UnionSet *)calloc(1, sizeof(UnionSet));
    u->father = (int *)calloc(n + 1, sizeof(int));
    u->val = (int *)calloc(n + 1, sizeof(int));
    u->size = (int *)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++) {
        u->father[i] = i;
        u->val[i] = 0;
        u->size[i] = 1;
    }
    return u;
}

void clear(UnionSet *u) {
    if (!u) return;
    free(u->father);
    free(u->val);
    free(u->size);
    free(u);
    return ;
}

int find(UnionSet *u, int x) {
    if (u->father[x] == x) return x;
    int root = find(u, u->father[x]);
    u->val[x] += u->val[u->father[x]];
    u->val[x] %= 3;
    u->father[x] = root;
    return root;
} 

int merge(UnionSet *u, int a, int b, int rlt) {
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return 0;
    if (u->size[fa] < u->size[fb]) {
        u->father[fa] = fb;
        u->size[fb] += u->size[fa];
        u->val[fa] = (-u->val[a] + rlt + u->val[b] + 3) % 3;
    } else {
        u->father[fb] = fa;
        u->size[fa] += u->size[fb];
        u->val[fb] = (-u->val[b] - rlt + u->val[a] + 3) % 3;
    }
    return 1;
}

#define MAX_N 50000
UnionSet *u = init_UnionSet(MAX_N);

int main() {
    int n, k, ans = 0;
    cin >> n >> k;
    while (k--) {
        int d, x, y;
        cin >> d >> x >> y;
        if (x > n || y > n) {
            ans++;
            continue;
        }
        switch (d) {
            case 1: {
                int fx = find(u, x), fy = find(u, y);
                if (fx == fy) {
                    /*已经有了关系*/
                    if ((u->val[x] - u->val[y] + 3) % 3 != 0) {
                        ans++;
                    }
                } else {
                    /*还没发生关系*/
                    merge(u, x, y, 0);
                }
            } break;
            case 2: {
                if (x == y) {
                    ans += 1;
                } else {
                    int fx = find(u, x), fy = find(u, y);
                    if (fx - fy) {
                        /*还没关系*/
                        merge(u, x, y, 2);
                    } else {
                        /*已经有了关系*/
                        if ((u->val[x] - u->val[y] + 3) % 3 != 2) {
                            ans++;
                        } 
                    }
                }
            } break;
        }
    }

    cout << ans << endl;
    return 0;
}
