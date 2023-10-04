#include <iostream>
using namespace std;

#define MAX_N 10000
int n, k;
double arr[MAX_N + 5];
double maxX = 0.0;

void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        maxX = max(maxX, arr[i]);
    }
    return ;
}

bool isSucc(double len) { // 切长度为len的绳子，够不够K条
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += (int)(arr[i] / len);
        if (cnt >= k) {
            return true;
        }
    }
    return false;
}

// 1111100000
double bs() {
    double l = 0.0, r = maxX;
    while (r - l > 0.001) {
        double mid = (l + r) / 2;
        if (isSucc(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

void output() {
    double ans = bs();
    //printf("%.2lf\n", ans);不能这么写！！！这么写是四舍五入！！而题目要求直接舍弃！！
    printf("%d.%d%d\n", (int)ans, (int)(ans * 10) % 10, (int)(ans * 100) % 10);
    return ;
}


int main() {
    input();
    output();
    return 0;
}