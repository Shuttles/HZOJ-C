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


int64_t num[max_n + 5] = {0};

typedef struct Node {
    int64_t sum;
    int64_t tag;//懒标记
    int64_t cnt;//当前维护区间长度
} Node;

Node Tree[4 * max_n + 6];

void up(int ind) {
    Tree[ind].sum = Tree[ind * 2].sum + Tree[ind * 2 + 1].sum;
    return ;
}

void build(int ind, int left, int right) {
    Tree[ind].cnt = (right - left + 1);
    if (left == right) {
        Tree[ind].sum = num[left];
        return ;
    }
    int mid = (left + right) / 2;
    build(ind * 2, left, mid);
    build(ind * 2 + 1, mid + 1, right);
    up(ind);
    return ;
}

void down(int ind) {
    if (Tree[ind].tag) {
        Tree[ind * 2].tag += Tree[ind].tag;
        Tree[ind * 2 + 1].tag += Tree[ind].tag;
        
        Tree[ind * 2].sum += Tree[ind].tag * Tree[ind * 2].cnt;
        Tree[ind * 2 + 1].sum += Tree[ind].tag * Tree[ind * 2 + 1].cnt;
        
        Tree[ind].tag = 0;
    }
    return ;
}
/*区间查询*/
int64_t q(int ind, int x, int y, int left, int right) {
    if (x <= left && right <= y) return Tree[ind].sum;
    
    down(ind);//懒标记下沉

    int64_t res = 0;
    int mid = (left + right) / 2;

    if (x <= mid) {
        res += q(ind * 2, x, y, left, mid);
    } 
    if (y > mid) {
        res += q(ind * 2 + 1, x, y, mid + 1, right);
    }
    return res;
}

/*区间修改*/
void modify(int ind, int x, int y, int64_t d, int left, int right) {
    if (x <= left && right <= y) {
        Tree[ind].tag += d;/*一定要是+=!!!!!!*/
        Tree[ind].sum += d * Tree[ind].cnt;
        return ;
    }

    down(ind);//懒标记下沉

    
    int mid = (left + right) / 2;
    if (x <= mid) {
        modify(2 * ind, x, y, d, left, mid);
    } 
    if (y > mid) {
        modify(2 * ind + 1, x, y, d, mid + 1, right);
    }
    up(ind);//上提操作发生在递归之后
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
        int64_t a, b, c, d;
        cin >> a >> b >> c;
        if (a == 1) {
            cin >> d;
            modify(root, b, c, d, 1, n);
        } else if (a == 2) {
            cout << q(root, b, c, 1, n) << endl; 
        }
    }

    return 0;
}

