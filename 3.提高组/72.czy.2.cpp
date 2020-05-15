/*************************************************************************
	> File Name: 72.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  5/10 12:15:28 2020
 ************************************************************************/

#include<iostream>
using namespace std;

typedef struct UnionSet {
    int *father, *val;
} UnionSet;

UnionSet *init_UnionSet(int n) {
    UnionSet *u = (UnionSet *)calloc(1, sizeof(UnionSet));
    u->father = (int *)calloc(n + 1, sizeof(int));
    u->val = (int *)calloc(n + 1, sizeof(int));


    for (int i = 1; i <= n; i++) {
        u->father[i] = i;
        u->val[i] = 0;/*跟自己肯定是打成平手*/
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


int find(UnionSet *u, int x) {
    if (u->father[x] == x) return x;
    int root = find(u, u->father[x]);
    /*父结点一定已经挂到root结点上了！*/
    u->val[x] += u->val[u->father[x]];
    u->val[x] %= 3;
    return u->father[x] = root;
}

int merge(UnionSet *u, int a, int b, int rlt) {
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return 0;
    /*做完find操作之后，val[a], val[b]的值就改变了！*/
    u->father[fb] = fa;
    u->val[fb] = (-rlt + u->val[a] - u->val[b] + 3) % 3;
    return 1;    
}

int main() {
    int n, m;
    cin >> n >> m;
    UnionSet *u = init_UnionSet(n);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            merge(u, b, c, 2);
        } else {
            if (find(u, b) - find(u, c)) {
                cout << "Unknown" << endl;
            } else {
                switch ((u->val[b] - u->val[c] + 3) % 3) {
                    case 0: {
                        cout << "Tie" << endl;
                    } break;
                    case 1: {
                        cout << "Loss" << endl;
                    } break;
                    case 2:{
                        cout << "Win" << endl;
                    } break;
                }
            }
        }
    }

    free(u);
    return 0;
}
