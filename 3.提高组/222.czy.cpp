/*************************************************************************
	> File Name: 222.czy.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  5/22 09:04:04 2020
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 10000
#define lc(ind) (ind << 1)
#define rc(ind) (ind << 1 | 1)

typedef struct Node {
    int sum;
} Node;

Node tree[(MAX_N << 2) + 5];

int root = 1;//线段树根节点下标
int arr[MAX_N + 5];//原数组

void UP(int ind) {
    tree[ind].sum = max(tree[lc(ind)].sum, tree[rc(ind)].sum);
    return ;
}

void build(int ind, int l, int r) {
    /*ind是当前结点下标，l，r是当前结点所维护的区间范围*/
    if (l == r) {
        tree[ind].sum = arr[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lc(ind), l, mid);
    build(rc(ind), mid + 1, r);
    UP(ind);//上提操作
    return ;
}

void modify(int ind, int x, int y, int l, int r) {
    /*ind为当前结点下标，将下标为x的位置值改为y，当前结点维护的区间为l~r*/
    if (l == r) {
        if (l - x) return ;
        tree[ind].sum = y;
        return ;
    }

    int mid = (l + r) >> 1;
    if (x <= mid) modify(lc(ind), x, y, l, mid);
    else modify(rc(ind), x, y, mid + 1, r);
    UP(ind);
    return ;
}

int query(int ind, int x, int y, int l, int r) {
    if (x <= l && r <= y) {
        return tree[ind].sum;
    }
    int ans = 0x80000000, mid = (l + r) >> 1;
    if (x <= mid) ans = max(ans, query(lc(ind), x, y, l, mid));
    if (y > mid) ans = max(ans, query(rc(ind), x, y, mid + 1, r));
    return ans;
}


int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    build(root, 1, n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) modify(root, b, c, 1, n);
        else {
            cout << query(root, b, c, 1, n) << endl;
        }
    }


    return 0;
}
