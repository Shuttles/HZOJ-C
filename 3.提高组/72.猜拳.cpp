/*************************************************************************
	> File Name: 72.猜拳.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  5/ 8 22:36:46 2020
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;

#define MAX_N 10000

typedef struct UnionSet {
    int *father, *val;/*val[i]记录i到其父结点之间的权值(即关系)*/
    /*如果能赢父结点，val[i] = 1, 平父结点，va[i] = 0, 赢父结点, val[i] = 2*/
} UnionSet;

UnionSet *init_UnionSet(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->father = (int *)calloc(n + 1, sizeof(int));
    u->val = (int *)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++) {
        u->father[i] = i;
        u->val[i] = 0;/*自己和自己打成平手*/
    }

    return u;
}

void clear_UnionSet(UnionSet *u) {
    if (!u) return ;
    free(u->father);
    free(u->val);
    free(u);
    return ;
}

int find(UnionSet *u, int ind) {
    if (ind == u->father[ind]) return ind;
    /*一定会做路径压缩, 所以ind的父结点一定已经直接挂在root结点上了*/
    int root = find(u, u->father[ind]);
    u->val[ind] += u->val[u->father[ind]];
    u->val[ind] %= 3;
    return u->father[ind] = root;/*路径压缩*/
}

int merge(UnionSet *u, int a, int b, int relation) {
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return 0;
    /*因为调用find(), 那么就一定会做路径压缩，所以val[a]就变成了a到其根节点之间的关系，val[b]同理*/
    u->father[fa] = fb;
    u->val[fa] = (relation + u->val[b] - u->val[a] + 3) % 3;
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
                merge(u, b, c, 2);
            } break;
            case 2: {
                int fb = find(u, b);
                int fc = find(u, c);
                /*调用find之后就完成了路径压缩！val的值也就变了！*/
                if (fb - fc) cout << "Unknown" << endl;
                else {
                    switch ((u->val[b] - u->val[c] + 3) % 3) {
                        case 0: {
                            cout << "Tie" << endl;
                        } break;
                        case 1: {
                            cout << "Loss" << endl;
                        } break;
                        case 2: {
                            cout << "Win" << endl;
                        } break;
                    }
                }
            } break;
        }
    }

    return 0;
}
