/*************************************************************************
	> File Name: 334.Interval_GCD.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  4/28 16:26:32 2020
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cinttypes>
using namespace std;

#define MAX_N 500000

int64_t gcd(int64_t a, int64_t b) {
    /*辗转相除法*/
    return (b ? gcd(b, a % b) : a);
}

typedef struct Node {
    int64_t gcd_num;
}Node;

Node tree[MAX_N * 4 + 5];

void UP(int ind) {
    tree[ind].gcd_num = gcd(tree[ind * 2].gcd_num, tree[ind * 2 + 1].gcd_num);
    return ;
}

void build(int ind, int l, int r) {
    if (l == r) {
        //tree[ind].gcd_num = 0;
        return ;
    }
    int mid = (l + r) / 2;
    build(ind * 2, l , mid);
    build(ind * 2 + 1, mid + 1, r);

    return ;
}

void modify(int ind, int x, int64_t y, int l, int r) {
    if (l == r) {
        if (x != l) return ;
        tree[ind].gcd_num += y;
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

int64_t query(int ind, int x, int y, int l, int r) {
    if (x > y) return 0;
    if (x <= l && r <= y) {
        return tree[ind].gcd_num;
    }
    int64_t res = 0;
    int mid = (l + r) / 2;
    if (x <= mid) {
        res = gcd(res, query(ind * 2, x, y, l, mid));
    }
    if (y > mid) {
        res = gcd(res, query(ind * 2 + 1, x, y, mid + 1, r));
    }
    return res;
}

int64_t c_tree[MAX_N + 5];/*树状数组*/
int64_t Lowbit(int64_t x) {
    return x & (-x);
}

void change(int x, int64_t num, int n) {
    while  (x <= n) {
        c_tree[x] += num;
        x += Lowbit(x);
    }
    return ;
}

int64_t q(int x) {
    int64_t res = 0;
    while (x) {
        res += c_tree[x];
        x -= Lowbit(x);
    }
    return res;
}


int main() {
    int n, m;
    cin >> n >> m;
    int root = 1;
    build(root, 1, n);
    int64_t this_num = 0, pre_num = 0;
    for (int i = 1; i <= n; i++) {
        cin >> this_num;
        modify(root, i, this_num - pre_num, 1, n);
        change(i, this_num - pre_num, n);
        pre_num = this_num;
    }

    char s[15] = {0};
    for (int i = 1; i <= m; i++) {
        cin >> s;
        int64_t l, r;
        if (s[0] == 'Q') {
            int64_t x;
            cin >> l >> r;
            x = q(l);
            cout << abs(gcd(x, query(root, l + 1, r, 1, n))) << endl;
        } else if (s[0] == 'C') {
            int64_t  d;
            cin >> l >> r >> d;
            modify(root, l, d, 1, n);
            modify(root, r + 1, -d, 1, n);
            change(l, d, n);
            change(r + 1, -d, n);
        } else {
            continue;
        }
    }

    return 0;
}
