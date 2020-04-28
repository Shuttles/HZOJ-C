/*************************************************************************
	> File Name: 333.最大区间子段和.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  4/28 10:52:15 2020
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 500000

#define SWAP(a, b) {\
    __typeof(a) _temp = (a);\
    (a) = (b); (b) = _temp;\
}

int num[MAX_N + 5];

typedef struct Node {
    int sum;
    int mmax, lmax, rmax;
} Node;

Node tree[4 * MAX_N + 5];

void update(Node *a, Node *b) {
    /*把b的结果整理进a中*/
    int temp = max(b->mmax, a->rmax + b->lmax);
    a->mmax = max(a->mmax, temp);
    a->lmax = max(a->lmax, a->sum + b->lmax);
    a->rmax = max(b->rmax, b->sum + a->rmax);

    a->sum += b->sum;
    return ;
}

void UP(int ind) {
    tree[ind] = tree[ind * 2];
    update(&tree[ind], &tree[ind * 2 + 1]);
    return ;
}

/*
void UP(int ind) {
    tree[ind].sum = tree[ind * 2].sum + tree[ind * 2 + 1].sum;
    tree[ind].lmax = max(tree[ind * 2].lmax, tree[ind * 2].sum + tree[ind * 2 + 1].lmax);
    tree[ind].rmax = max(tree[ind * 2 + 1].rmax, tree[ind * 2 + 1].sum + tree[ind * 2].rmax);
    tree[ind].mmax = max(tree[ind * 2].mmax, tree[ind * 2 + 1].mmax);
    tree[ind].mmax = max(tree[ind * 2].lmax + tree[ind * 2 + 1].rmax, tree[ind].mmax);
    return ;
}
*/

void build(int ind, int l, int r) {
    if (l == r) {
        tree[ind].sum = tree[ind].mmax = tree[ind].lmax = tree[ind].rmax = num[l];
        return ;
    }
    int mid = (l + r) / 2;
    build(ind * 2, l, mid);
    build(ind * 2 + 1, mid + 1, r);
    UP(ind);
    return ;
}

/*单点修改*/
void modify(int ind, int x, int y, int l, int r) {
    /*将x点的值改为y*/
    if (l == r) {
        tree[ind].sum = tree[ind].mmax = tree[ind].lmax = tree[ind].rmax = y;
        return ;
    }
    int mid = (l + r) / 2;
    if (x <= mid) {
        modify(ind * 2, x, y, l, mid);
    } else {
        modify(ind * 2 + 1, x, y, mid + 1, r);
    }
    UP(ind);
    return ;
}

void query(int ind, int x, int y, int l, int r, Node *ans) {
    /*为什么需要通过传出参数返回呢？因为通过左右子树的最大区间子段和不能推出父结点的最大区间子段和*/
    if (x <= l && r <= y) {
        if (l == x) {
            /*这是找到的第一个节点*/
            ans->sum = tree[ind].sum;
            ans->mmax = tree[ind].mmax;
            ans->lmax = tree[ind].lmax;
            ans->rmax = tree[ind].rmax;
        } else {
            update(ans, &tree[ind]);
        }
        return ;
    }
    int mid = (l + r) / 2;
    if (x <= mid) {
        query(ind * 2, x, y, l, mid, ans);
    } 
    if (y > mid) {
        query(ind * 2 + 1, x, y, mid + 1, r, ans);
    }
    return ;
}


int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }

    /*建树*/
    int root = 1;
    build(root, 1, n);

    for (int i = 1; i <= m; i++) { 
        int k, x, y;
        cin >> k >> x >> y;
        if (k == 1) {
            Node ans;
            if (x > y) SWAP(x, y);
            query(root, x, y, 1, n, &ans);
            cout << ans.mmax << endl;
        } else if (k == 2){
            modify(root, x ,y, 1, n);
        }
    }
    
    return 0;
}
