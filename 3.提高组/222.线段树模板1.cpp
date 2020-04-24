/*************************************************************************
	> File Name: 222.线段树模板1.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  4/24 20:45:19 2020
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cinttypes>
using namespace std;

#define max_n 10000


int num[max_n + 5] = {0};

typedef struct Node {
    int max_num;

} Node;

Node Tree[5 * max_n + 6];

void up(int ind) {
    Tree[ind].max_num = max(Tree[ind * 2].max_num, Tree[ind * 2 + 1].max_num);
    return ;
}

void build(int ind, int left, int right) {
    if (left == right) {
        Tree[ind].max_num = num[right];
        return ;
    }
    int mid = (left + right) / 2;
    build(ind * 2, left, mid);
    build(ind * 2 + 1, mid + 1, right);
    up(ind);
    return ;
}

/*区间查询*/
int q(int ind, int x, int y, int left, int right) {
    if (x <= left && right <= y) return Tree[ind].max_num;

    int res = INT32_MIN;
    int mid = (left + right) / 2;

    if (x <= mid) {
        res = q(ind * 2, x, y, left, mid);
    } 
    if (y > mid) {
        res = max(res, q(ind * 2 + 1, x, y, mid + 1, right));
    }
    return res;
}

/*单点修改*/
void modify(int ind, int x, int y, int left, int right) {
    if (left == right) {
        Tree[ind].max_num = y;
        return ;
    }
    int mid = (left + right) / 2;
    if (x <= mid) {
        modify(2 * ind, x, y, left, mid);
    } else {
        modify(2 * ind + 1, x, y, mid + 1, right);
    }
    up(ind);
    return ;
}



int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }

    int root = 1;
    build(root, 1, n);/*建立线段树*/
    
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            modify(root, b, c, 1, n);
        } else if (a == 2) {
            cout << q(root, b, c, 1, n) << endl; 
        }
    }

    return 0;
}

