/*************************************************************************
	> File Name: 71.朋友圈.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  5/ 8 20:30:37 2020
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;



typedef struct UnionSet {
    int *father, *size;//结点个数
    int n;
} UnionSet;

UnionSet *init_UnionSet(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
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
    if (!u) return ;
    free(u->father);
    free(u->size);
    free(u);
    return ;
}

int find(UnionSet *u, int ind) {
    if (u->father[ind] == ind) return ind;
    u->father[ind] = find(u, u->father[ind]);/*路径压缩*/
    return u->father[ind];
}

#define SWAP(a, b) {\
    __typeof(a) _temp = (a);\
    (a) = (b); (b) = _temp;\
}

int merge(UnionSet *u, int a, int b) {
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return 0;

    if (u->size[fa] < u->size[fb]) SWAP(fa, fb);
    u->father[fb] = fa;
    u->size[fa] += u->size[fb];/*按秩优化*/
    return 1;
}

int main() {
    int n, m;
    cin >> n >> m;
    UnionSet *u = init_UnionSet(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        switch (a) {
            case 1: {
                merge(u, b, c);
            } break;
            case 2: {
                int fb = find(u, b);
                int fc = find(u, c);
                printf("%s\n", (fb - fc ? "No" : "Yes"));
            } break;
        }
    }
    return 0;
}
