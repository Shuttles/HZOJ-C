/**
* Author : Xiuchen
* Date : 2020-05-22-19.40.54
* Description : D.cpp
*/
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<cmath>
#include<math.h>
#include<iostream>
#include<algorithm>
//#define DEBUG
#define dbg(x) cout << #x << " = "<< (x) << endl
#define dbg2(x1,x2) cout << #x1 << " = " << x1 << " " << #x2 << " = " << x2 << endl
#define dbg3(x1,x2,x3) cout<< #x1 << " = " << x1 << " " << #x2 << " = " << x2 << " " << #x3 << " = " << x3 <<endl
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 1e6 + 100;
int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}
char s[maxn];
int m, n;
struct SegmentTree{
    int l, r;
    int num;
    int tag;
} t[maxn * 4];
void push_up(int p){
    t[p].num = t[p * 2].num + t[p * 2 + 1].num;
}
void push_down(int p){
    if(t[p].tag != -1){
        t[p * 2].tag = t[p].tag;
        t[p * 2 + 1].tag = t[p].tag;
        t[p].tag = -1;
        if(t[p * 2].tag == 0) t[p * 2].num = 0;
        else t[p * 2].num = t[p * 2].r - t[p * 2].l + 1;
        if(t[p * 2 + 1].tag == 0) t[p * 2 + 1].num = 0;
        else t[p * 2 + 1].num = t[p * 2 + 1].r - t[p * 2 + 1].l + 1;
    }
}
void build(int p, int l, int r){
    t[p].l = l, t[p].r = r;
    t[p].tag = -1;
    if(l == r){
        if(s[l] == '0') t[p].num = 0;
        else t[p].num = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    push_up(p);
//    dbg3(l, r, t[p].num);
}
void change(int p, int l, int r, int d){
    if(l <= t[p].l && t[p].r <= r){
        t[p].tag = d;
        if(d == 0) t[p].num = 0;
        else t[p].num = t[p].r - t[p].l + 1;
        return;
    }
    int mid = (t[p].l + t[p].r) / 2;
    push_down(p);
    if(l <= mid) change(p * 2, l, r, d);
    if(mid < r) change(p * 2 + 1, l, r, d);
    push_up(p);
}
int query(int p, int l, int r){
    if(l <= t[p].l && t[p].r <= r) return t[p].num;
    push_down(p);
//    dbg2(p, t[p].num);
    int mid = (t[p].l + t[p].r) / 2, ans = 0;
    if(l <= mid) ans += query(p * 2, l, r);
    if(mid < r) ans += query(p * 2 + 1, l, r);
    return ans;
}
int main(){
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    scanf("%s", s + 1);
    scanf("%d", &m);
    n = strlen(s + 1);
    build(1, 1, n);
//    query(1, 1, 1);
//    dbg(t[2].num);
    int l, r, x;
    while(m--){
        scanf("%d%d%d", &x, &l, &r);
        int num1 = query(1, l, r), num0 = r - l + 1 - num1;
//        dbg2(num1, num0);
        if(num1 == 0 || num0 == 0) continue;
        if(x == 1){
            change(1, l, l + num0 - 1, 0);
            change(1, r - num1 + 1, r, 1);
        }
        else if(x == 2){
            change(1, l, l + num1 - 1, 0);
            change(1, r - num0 + 1, r, 1);
        }
    }
    for(int i = 1; i <= n; i++){
        if(query(1, i, i) == 1) printf("1");
        else printf("0");
    }
    printf("\n");
    return 0;
}
